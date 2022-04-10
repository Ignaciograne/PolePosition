package com.server.pole;

public class GameObject {
    private int position;
    private int health;
    private int points;
    private int acceleration;

    //Position
    public void setPosition(int position){
            this.position = position;
    }

    public int getPosition(){
            return position;
    }

    //Health
    public void setHealth(int health){
            this.health = health;
    }

    public int getHealth(){
            return health;
    }

    //Points
    public void setPoints(int points){
            this.points = points;
    }
    public int getPoints(){
            return points;
    }
    
    //Acceleration
    public void setAcceleration(int acceleration){
            this.acceleration = acceleration;
    }
    public int getAcceleration(){
            return acceleration;
    }
}