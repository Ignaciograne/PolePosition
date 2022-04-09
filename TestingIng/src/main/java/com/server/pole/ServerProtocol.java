package com.server.pole;

import org.json.JSONArray;
import org.json.JSONObject;
import java.util.*;

public class ServerProtocol {
	private static final int AVAILABLECARS = 0;
	private static final int SELECTCAR = 1;
    
    private static final int DEFINEOBJECTS = 2;
    private static final int ANOTHER = 3;
    
    private static String[] carColors = {"azul", "blanco", "morado", "rojo"};
    private static List valid = Arrays.asList(carColors);

    private static final int NUMJOKES = 5;

    //private int state = SELECTCAR;
    private int state = AVAILABLECARS;
    
    private static JSONObject carsAvailable = new JSONObject()
    		.put("Azul", 1)
    		.put("Blanco", 1)
    		.put("Morado", 1)
    		.put("Rojo", 1);
    
    

    GameObjectsFactory objectsFactory = new GameObjectsFactory();
    //GameObject gameObject;
    
    public JSONObject processInput(JSONObject theInput) {
        JSONObject theOutput = new JSONObject();

        if (state == AVAILABLECARS) {
        	theOutput = carsAvailable; 
            //theOutput = "Hola! Por favor ingrese los obstaculos deseados";
            //state = SENTKNOCKKNOCK;
        	state = SELECTCAR;
        } else if (state == SELECTCAR) {
        	Iterator<String> maKeys = theInput.keys();
        	String maKey = maKeys.next();
            if (carsAvailable.has(maKey) && Integer.parseInt(carsAvailable.get(maKey).toString().replace("\n", "")) == 1) {
            	System.out.println("Todo bien");
            	carsAvailable.put(""+maKey, 0);
            	theOutput = carsAvailable;
                
                state = DEFINEOBJECTS;
            } else {
            	System.out.println("Nopo nopo bitcho nopo");
                theOutput = carsAvailable;
            }
            System.out.println("Mira putito: " + carsAvailable);
        } else if (state == DEFINEOBJECTS) {
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
	        	theOutput.put("Li)fe", lifeAr);
        	
        	
        	
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