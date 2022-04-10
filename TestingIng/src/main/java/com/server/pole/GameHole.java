package com.server.pole;

public class GameHole extends GameObject {

    public GameHole(int position){
            setPosition(position);
            setHealth(0);
            setPoints(0);
            setAcceleration(-9);
    }
}