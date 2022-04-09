package com.server.pole;

import java.net.*;
import java.util.*;

import org.json.JSONObject;

import java.io.*;

public class MultiServerThread extends Thread {
    private Socket socket = null;

    public MultiServerThread(Socket socket) {
        super("KKMultiServerThread");
        this.socket = socket;
    }
    
    public void run() {

        try (
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(
                new InputStreamReader(
                    socket.getInputStream()));
        ) {
            String inputLine;//, outputLine;
            JSONObject outputLine;
            ServerProtocol kkp = new ServerProtocol();
            //out.println("Seleccione su color: ");
            JSONObject nuller = new JSONObject("{1:2}");
            outputLine = kkp.processInput(nuller);
            out.println(outputLine);
            
            //inputLine = in.readLine();
            //JSONObject obj = new JSONObject(inputLine.trim());
            
            //outputLine = kkp.processInput(obj);
            /*JSONObject tr = new JSONObject("{\"Nombre\":\"Caca\"}");
            outputLine = tr;
            out.println(outputLine);*/

            while ((inputLine = in.readLine()) != null) {
            	System.out.println(inputLine);
            	JSONObject obj = new JSONObject(inputLine);
            	
            	//Just to print
            	Iterator<String> keys = obj.keys();

            	System.out.println(obj);
            	
            	while (keys.hasNext()) {
            		String key = keys.next();
            		System.out.println(key + " " + obj.get(key));
            	}  //Just to print
            	
            	outputLine = kkp.processInput(obj);
            	
            	//System.out.println(inputLine);

                //outputLine = kkp.processInput(inputLine);
                //System.out.println(inputLine);
            	//System.out.println("-----------------");
            	//System.out.println(outputLine);
            	
            	/*JSONObject tr = new JSONObject("{\"Nombre\":\"Caca\"}");
                outputLine = tr;
                out.println(outputLine);*/
            	
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