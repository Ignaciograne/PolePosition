import java.net.*;
import java.io.*;

public class GameServerProtocol {

    GameObjectFactory objectsFactory = new GameObjectFactory();
    GameObjects gameObject;

    public String processInput(String type, String theInput) {
	String theOutput;

	gameObject = objectsFactory.makeObject(type, Integer.parseInt(theInput.replace("Km", "")));

	theOutput = "{" + "\"position\":"+gameObject.getPosition() + ","+"\"health\":"+gameObject.getHealth() + ","+"\"points\":"+gameObject.getPoints() +"}";
	//System.out.println(gameObject.getPoints());
	//theOutput = gameObject.getPoints() + " | " + gameObject.getHealth() + " | " + gameObject.getPosition();

        //theOutput = "Hi! Please enter the objects you'd like in the circuit.";
	//Add code to just ask first client for inputs.
	//Add code to validate user input

        //return theOutput;
	return theOutput;
    }
}
