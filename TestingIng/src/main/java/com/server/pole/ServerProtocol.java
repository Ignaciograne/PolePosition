package com.server.pole;

import org.json.JSONArray;
import org.json.JSONObject;
import java.util.*;

public class ServerProtocol {
	private static final int AVAILABLECARS = 0;
	private static final int SELECTCAR = 1;
    private static final int DEFINEOBJECTS = 2;
    private static final int LETSPLAY = 3;

    private int state = AVAILABLECARS;
    
    private static JSONObject carsAvailable = new JSONObject()
    		.put("Azul", 1)
    		.put("Blanco", 1)
    		.put("Morado", 1)
    		.put("Rojo", 1);

    GameObjectsFactory objectsFactory = new GameObjectsFactory();
    private static ObjectLogger logger;
    
    public JSONObject processInput(JSONObject theInput) { //Defines the current state of the game
        JSONObject theOutput = new JSONObject();

        if (state == AVAILABLECARS) { //Display JSON with available cars to the client
        	theOutput = carsAvailable;
        	state = SELECTCAR;
        } else if (state == SELECTCAR) { //Allows client to choose a car from the available cars list
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
        	if (logger == null) { //Implementation of singleton
        		logger = ObjectLogger.getInstance();
        	
        		Iterator<String> keys = theInput.keys();
        		
        		JSONArray turboAr = new JSONArray();
        		JSONArray holeAr = new JSONArray();
        		JSONArray lifeAr = new JSONArray();
	        	while (keys.hasNext()) {
	        		String key = keys.next();
	        		GameObject gameObject = objectsFactory.makeObject(theInput.get(key).toString().replace("\n", ""), Integer.parseInt(key.toString().replace("km", "")));
	        		JSONObject jo = new JSONObject();
	        		
	        		jo.put("position", gameObject.getPosition());
	        		jo.put("health", gameObject.getHealth());
	        		jo.put("points", gameObject.getPoints());
	        		jo.put("acceleration:", gameObject.getAcceleration());
	        		
	        		//switch
	        		if (theInput.get(key).toString().replace("\n", "").equalsIgnoreCase("turbo"))
	        			turboAr.put(jo);
	        		if (theInput.get(key).toString().replace("\n", "").equalsIgnoreCase("hueco"))
	        			holeAr.put(jo);
	        		if (theInput.get(key).toString().replace("\n", "").equalsIgnoreCase("vida"))
	        			lifeAr.put(jo);
	        		
	        	}
	        	
	        	theOutput.put("Turbo", turboAr);
	        	theOutput.put("Hole", holeAr);
	        	theOutput.put("Life", lifeAr);
	        	
	        	state = LETSPLAY;
	        	
        	} else {
        		System.out.println("Ya habias definido los obstaculos guapo");
        		state = LETSPLAY;
        	}
        	
        	
        	
        } else if (state == LETSPLAY) {
            System.out.println("STAMOS JUGANDO PAPÁ");
        }
        return theOutput;
    }
}