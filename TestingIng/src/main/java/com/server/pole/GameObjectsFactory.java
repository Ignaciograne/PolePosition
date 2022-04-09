package com.server.pole;

public class GameObjectsFactory {
    public GameObject makeObject(String newObjectType, int objectPosition){
            //GameObject newObject = null;

            if (newObjectType.equalsIgnoreCase("Turbo")) {
                    return new GameTurbo(objectPosition);
            } else if (newObjectType.equalsIgnoreCase("Hueco")) {
                    return new GameHole(objectPosition);
            } else if (newObjectType.equalsIgnoreCase("Vida")) {
                    return new GameLife(objectPosition);
            } else {
                    return null;
            }
    }
}
