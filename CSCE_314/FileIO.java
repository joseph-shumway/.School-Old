import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class FileIO {
    private ArrayList<String> list;


    // Constructor
    public FileIO() {
        this.list = new ArrayList<String>(0);
    }


    // Check if text file can be opened
    public boolean openTextFile(String filename) {
        Scanner infile;
        
        try {
            infile = new Scanner(new FileReader(filename));
            return true;
            
        } catch (Exception e) {
            System.out.println("File not found");
            return false;
        }
    }


    // read, filter, and tokenize from given file
    public ArrayList<String> readTextFile(String filename) {
        Scanner infile;
        String delimiters = "\\t|,|;|\\.|\\?|!|:|@|\\[|\\]|\\(|\\)|\\{|\\}|_|\\*|/";
        ArrayList<String> sub_list;

        if (openTextFile(filename)) {
            try {
                infile = new Scanner(new FileReader(filename));

                while (infile.hasNextLine()) {

                    String line = infile.nextLine();
                    if (line.length() == 0) {
                        continue;
                    }

                    if (line.substring(0,1).matches(".*\\d.*")) {continue;}
                    
                    // clean up punctuation
                    line = line.replaceAll(delimiters, "");
                    
                    sub_list.clear();
                    sub_list.addAll(Arrays.asList(line.toLowerCase().split(" ")));

                    // checks if token exists
                    if (sub_list.contains())

                    // tokenize and lowercase everything, then add to our ArrayList
                    list.addAll();
                }

                
                // int count = 0;
                // for (String string : list) {
                //     System.out.println("[" + count + "] " + string);
                //     count++;
                // }

            } catch (FileNotFoundException e) {
                System.out.println("File not found");
            }
        }

        return list;
    }

    public void writeData() {
        PrintWriter outfile = null;

        try {
            outfile = new PrintWriter("debug1.txt");

            int count = 0;
            for (String string : list) {
                System.out.println("[" + count + "] " + string);
                outfile.write(string + "\n");
                count++;
            }



        } catch (FileNotFoundException e) {
            System.out.println("Could not output to debug1.txt");
        }
    }

    // Getters and Setters ----------------------------------------------
    public ArrayList<String> getList() {
        return list;
    }

    public void setList(ArrayList<String> list) {
        this.list = list;
    }


}
