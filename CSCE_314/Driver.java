public class Driver {

	public static void main(String[] args) {
		FileIO fileIO1 = new FileIO();

		fileIO1.readTextFile("C:/.School/CSCE_314/PT1.txt");
		fileIO1.readTextFile("C:/.School/CSCE_314/YT1.txt");

		Hashing hashmap = new Hashing(fileIO1.getWordList());
		hashmap.writeListEqual();
		hashmap.writeListDifference();
		hashmap.writeEqual();
		hashmap.writeDifference();

	}
}
