package com.server.pole;

import org.json.JSONArray;
import org.json.JSONObject;
import java.util.*;

public class ServerProtocol {
    private static final int SELECTCAR = 0;
    private static final int SENTKNOCKKNOCK = 1;
    private static final int SENTCLUE = 2;
    private static final int ANOTHER = 3;
    
    private static String[] carColors = {"azul", "blanco", "morado", "rojo"};
    private static List valid = Arrays.asList(carColors);

    private static final int NUMJOKES = 5;

    //private int state = SELECTCAR;
    private int state = SELECTCAR;
    private int currentJoke = 0;

    private String[] clues = { "Turnip", "Little Old Lady", "Atch", "Who", "Who" };
    private String[] answers = { "Turnip the heat, it's cold in here!",
                                 "I didn't know you could yodel!",
                                 "Bless you!",
                                 "Is there an owl in here?",
                                 "Is there an echo in here?" };

    GameObjectsFactory objectsFactory = new GameObjectsFactory();
    //GameObject gameObject;
    
    public JSONObject processInput(JSONObject theInput) {
        JSONObject theOutput = new JSONObject();

        if (state == SELECTCAR) {
            //theOutput = "Hola! Por favor ingrese los obstaculos deseados";
            //state = SENTKNOCKKNOCK;
        	state = SENTCLUE;
        }/* else if (state == SENTKNOCKKNOCK) {
            if (valid.contains(theInput)) {
                //theOutput = "You selected " + theInput;
                //state = SENTCLUE;
            } else {
                //theOutput = theInput + " not a valid color yo";
            }
        }*/ else if (state == SENTCLUE) {
        		Iterator<String> keys = theInput.keys();
        	
        		JSONArray turboAr = new JSONArray();
        		JSONArray holeAr = new JSONArray();
        		JSONArray lifeAr = new JSONArray();
	        	while (keys.hasNext()) {
	        		String key = keys.next();
	        		GameObject gameObject = objectsFactory.makeObject(theInput.get(key).toString().replace("\n", ""), Integer.parseInt(key.toString().replace("km", "")));
	        		JSONObject jo = new JSONObject();
	        		//System.out.println("AQUI ESTOY YO: " + gameObject);
	        		jo.put("position", gameObject.getPosition());
	        		jo.put("health", gameObject.getHealth());
	        		jo.put("points", gameObject.getPoints());
	        		
	        		//JSONArray ja = new JSONArray();
	        		//ja.put(jo);
	        		//backupAr.put(jo);
	        		
	        		//switch()
	        		if (theInput.get(key).toString().replace("\n", "").equalsIgnoreCase("turbo"))
	        			turboAr.put(jo);
	        		if (theInput.get(key).toString().replace("\n", "").equalsIgnoreCase("hueco"))
	        				holeAr.put(jo);
	        		if (theInput.get(key).toString().replace("\n", "").equalsIgnoreCase("vida"))
	        				lifeAr.put(jo);
	        		
	        		//else {
	        		//	theOutput.put(theInput.get(key).toString().replace("\n", ""), backupAr);
	        			
	        		//}
	        			
	        			
	        		//System.out.println(key + " " + theInput.get(key));
	        		
	        	}
	        	
	        	theOutput.put("Turbo", turboAr);
	        	theOutput.put("Hole", holeAr);
	        	theOutput.put("Life", lifeAr);
        	
        	
        	
        } /*else if (state == ANOTHER) {
            if (theInput.equalsIgnoreCase("y")) {
                theOutput = "Knock! Knock!";
                if (currentJoke == (NUMJOKES - 1))
                    currentJoke = 0;
                else
                    currentJoke++;
                state = SENTKNOCKKNOCK;
            } else {
                theOutput = "Bye.";
                //state = WAITING;
            }
        }*/
        return theOutput;
    }
}