public class GameObjectFactory {
	public GameObjects makeObject(String newObjectType, int objectPosition){
		GameObjects newObject = null;

		if (newObjectType.equalsIgnoreCase("Turbo")) {
			return new GameLife(objectPosition); 
		} else if (newObjectType.equalsIgnoreCase("Hueco")) {
			return new GameHole(objectPosition);
		} else if (newObjectType.equalsIgnoreCase("Vida")) {
			return new GameLife(objectPosition);
		} else {
			return null;
		}
	}
} 
