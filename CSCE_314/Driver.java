import java.util.ArrayList;


public class Driver {

	public static void main(String[] args) {
		FileIO fileIO1 = new FileIO();
		FileIO fileIO2 = new FileIO();

		ArrayList<String> list1 = fileIO1.readTextFile("C:/.School/CSCE_314/PT1.txt");
		ArrayList<String> list2 = fileIO1.readTextFile("C:/.School/CSCE_314/YT1.txt");

		Hashing hashmap = new Hashing(fileIO1.getWordList());
		hashmap.writeListEqual();
		hashmap.writeListDifference();
		hashmap.writeEqual();

		//fileIO1.writeData();

	}
}
