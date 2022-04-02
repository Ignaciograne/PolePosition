import java.net.*;
import java.io.*;
import java.util.Arrays;
import java.util.ArrayList;

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
            String inputLine, outputLine;
            GameServerProtocol gsp = new GameServerProtocol();
            outputLine = gsp.processInput(null);
            out.println(outputLine);

            while ((inputLine = in.readLine()) != null) {
		ArrayList<String> inputList = new ArrayList<>(Arrays.asList(inputLine.split(",")));

                System.out.println(inputLine); //To verify user inputs
                System.out.println(inputList); //To verify user inputs

                outputLine = gsp.processInput(inputLine); //To send the client messages
                out.println(outputLine);
                if (outputLine.equals("Bye"))
                    break;
            }
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
