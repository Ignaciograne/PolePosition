package com.server.pole;

import java.net.*;
import java.io.*;

public class MultiServer {
    private static int count = 0;
    public static void main(String[] args) throws IOException {

    if (args.length != 0) {
        System.err.println("Usage: java KKMultiServer");
        System.exit(1);
    }

        int portNumber = 3403;
        boolean listening = true;
        
        try (ServerSocket serverSocket = new ServerSocket(portNumber)) { 
            while (listening) {
	            new MultiServerThread(serverSocket.accept()).start();
	            count++;
	            System.out.println("Sos el jugador.. "+count);
	        }
	    } catch (IOException e) {
            System.err.println("Could not listen on port " + portNumber);
            System.exit(-1);
        }
    }
}