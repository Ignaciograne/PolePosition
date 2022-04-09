import java.net.*;
import java.io.*;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Iterator;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;

public class GameServerThread extends Thread {
    private Socket socket = null;

    public GameServerThread(Socket socket) {
        super("GameServerThread");
        this.socket = socket;
    }
    
    public void run() {

        try (
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(
                new InputStreamReader(
                    socket.getInputStream()));
        ) {
            String inputLine;
	    String outputLine = "";
            GameServerProtocol gsp = new GameServerProtocol();
            //outputLine = gsp.processInput(null);
            //out.println(outputLine);

	    JSONParser parser = new JSONParser();
	    Iterator<String> iterator;

	    GameObjectFactory objectFactory = new GameObjectFactory();
	    GameObjects theObject = null;

            while ((inputLine = in.readLine()) != null) {
		//ArrayList<String> inputList = new ArrayList<>(Arrays.asList(inputLine.split(",")));

                System.out.println(inputLine); //To verify user inputs
                //System.out.println(inputList); //To verify user inputs

		JSONObject jsonObject = (JSONObject) parser.parse(inputLine);
		System.out.println(jsonObject);

		JSONArray kk = (JSONArray) jsonObject.get("Turbo");
		if (kk != null){
			iterator = kk.iterator();
			outputLine = outputLine + "\"turbo\":" + "[";
			while (iterator.hasNext()){
				//System.out.println(iterator.next());
                		outputLine = outputLine + "" + gsp.processInput("turbo", iterator.next());
				if (iterator.hasNext())
					outputLine = outputLine + ",";
			}
			outputLine = outputLine + "]";
		}

		JSONArray k3 = (JSONArray) jsonObject.get("Vida");
		if (k3 != null){
			iterator = k3.iterator();
			outputLine = outputLine + "\"vida\":" + "[";
			while (iterator.hasNext()){
				//System.out.println("Criminal"+iterator.next());
                		outputLine = outputLine + "" + gsp.processInput("vida", iterator.next());
				if (iterator.hasNext())
					outputLine = outputLine + ",";
			}
			outputLine = outputLine + "]";
		}

		JSONArray k2 = (JSONArray) jsonObject.get("Hueco");
		if (k2 != null){
			iterator = k2.iterator();
			outputLine = outputLine + "\"hueco\":" + "[";
			while (iterator.hasNext()) {
				//System.out.println(iterator.next());
                		outputLine = outputLine + "" + gsp.processInput("hueco", iterator.next());
				if (iterator.hasNext())
					outputLine = outputLine + ",";
			}
			outputLine = outputLine + "]";
		}

		outputLine = outputLine.replace("]\"", "],\"");
		outputLine = "{"+outputLine+"}";


                //outputLine = gsp.processInput(inputLine); //To send the client messages
                //out.println(outputLine);
                out.println(inputLine);

                if (outputLine.equals("Bye"))
                    break;
		System.out.println("Actu: And the winner is.. " + outputLine);
            }
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ParseException e) {
	    e.printStackTrace();
	}
    }
}
