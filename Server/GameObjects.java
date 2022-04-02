public class GameObjects {
	private int position;
	private int health;
	private int points;

	public GameObjects(int position, int health, int points) {
		this.position = position;
		this.health = health;
		this.points = points;
	}

	public int getPosition(){
		return position;
	}

	public int getHealth(){
		return health;
	}

	public int getPoints(){
		return points;
	}

}
