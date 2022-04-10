package com.server.pole;

public class ObjectLogger {
	private static ObjectLogger log;
	
	private ObjectLogger(){
		
	}
	
	public static ObjectLogger getInstance(){
		if (log == null) {
			log = new ObjectLogger();
		}
		
		return log;
	}
}