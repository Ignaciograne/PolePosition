package com.server.pole;

public class GameTurbo extends GameObject {

    public GameTurbo(int position){
            setPosition(position);
            setHealth(0);
            setPoints(2);
            setAcceleration(9);
    }
}