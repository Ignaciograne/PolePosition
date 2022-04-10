package com.server.pole;

public class GameLife extends GameObject {

    public GameLife(int position){
            setPosition(position);
            setHealth(1);
            setPoints(3);
            setAcceleration(0);
    }
}