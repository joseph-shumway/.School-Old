import java.util.ArrayList;


public class Driver {

	public static void main(String[] args) {
		FileIO fileIO_1 = new FileIO();
		FileIO fileIO_2 = new FileIO();

		// ArrayList<String> list_1 = fileIO_1.readTextFile("C:/.School/CSCE_314/PT1.txt");
		// fileIO_1.writeData();

		ArrayList<String> list_2 = fileIO_2.readTextFile("C:/.School/CSCE_314/YT1.txt");
		fileIO_2.writeData();

	}
}
