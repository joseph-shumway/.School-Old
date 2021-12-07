public class Driver {


	public static FileIO fio;
	public static String filename;
	public static Hashing hashmap;
	public static void main(String[] args) {
		

		readFiles();
		debug();
		createListEqual();
		createListDiff();
		createEqual();
		createDiff();

	}

	public static void readFiles() {
		fio = new FileIO();
		
		if (fio.openTextFile("C:/.School/CSCE_314/PT1.txt") && fio.openTextFile("C:/.School/CSCE_314/YT1.txt")) {
			fio.readTextFile("C:/.School/CSCE_314/PT1.txt");
			fio.readTextFile("C:/.School/CSCE_314/YT1.txt");
		}
	}

	public static void debug() {
		fio.writeData();
	}

	public static void createListEqual() {
		hashmap = new Hashing(fio.getWordList());
		
		hashmap.writeListEqual();
	}

	public static void createListDiff() {
		hashmap.writeListDifference();
	}

	public static void createEqual() {
		hashmap.writeEqual();
	}

	public static void createDiff() {
		hashmap.writeDifference();
	}

}
