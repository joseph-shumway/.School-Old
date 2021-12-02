import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class FileIO {

    private ArrayList<String> stringList;
    private ArrayList<Word> wordList;


    // Constructor
    public FileIO() {
        this.stringList = new ArrayList<String>(0);
        this.wordList = new ArrayList<Word>(0);
    }


    // Check if text file can be opened
    public boolean openTextFile(String filename) {
        
        // create our scanner
        try {
            Scanner infile = new Scanner(new FileReader(filename));
            infile.close();
            return true;
            
        } catch (Exception e) {
            System.out.println("File not found");
            return false;
        }
    }

    // read, filter, and tokenize from given file
    public void readTextFile(String filename) {
        Scanner infile;
        String delimiters = "\\t|,|;|\\.|\\?|!|:|@|\\[|\\]|\\(|\\)|\\{|\\}|_|\\*|/";
        ArrayList<String> subList = new ArrayList<String>();
        int yt = 0;
        int pt = 0;

        if (openTextFile(filename)) {
            try {
                infile = new Scanner(new FileReader(filename));
                
                // set counter vars for later
                if (filename.contains("YT")) {yt = 1;}
                if (filename.contains("PT")) {pt = 1;}

                while (infile.hasNextLine()) {

                    // skip numbers and empty lines
                    String line = infile.nextLine();
                    if (line.length() == 0 || line.matches(".*\\d.*")) {
                        continue;
                    }
                    
                    // clean up punctuation
                    line = line.replaceAll(delimiters, "");
                    
                    // clear out sub list and add line words to sub list
                    subList.clear();
                    subList.addAll(Arrays.asList(line.toLowerCase().split(" ")));

                    
                    for (String string : subList) {

                        // checks if token already exists
                        if (!stringList.contains(string)) {
                            stringList.add(string);
                            Word tempWord = new Word(string, pt, yt);
                            wordList.add(tempWord);
                            
                        } else {

                            

                            // find word and increment occurrences
                            for (int i = 0; i < wordList.size(); i++) {
                                if (wordList.get(i).getValue().equals(string)) {
                                    wordList.get(i).setCountPT(wordList.get(i).getCountPT() + (1 * pt));
                                    wordList.get(i).setCountYT(wordList.get(i).getCountYT() + (1 * yt));
                                }
                            }
                        }
                    }
                }

                stringList.sort(String::compareToIgnoreCase);
                wordList.sort(Word::compareTo);
                infile.close();


            } catch (FileNotFoundException e) {
                System.out.println("File not found");
            }
        }
    }

    public void writeData() {
        PrintWriter outfile = null;

        try {
            outfile = new PrintWriter("debug1.txt");

            for (Word word : wordList) {
                System.out.println("[PT: " + word.getCountPT() + "] " + "[YT: " + word.getCountYT() + "] " + word.getValue());
                outfile.write(word.getValue() + "\n");
            }

            outfile.close();

        } catch (FileNotFoundException e) {
            System.out.println("Could not output to debug1.txt");
        }
    }

    // Getters and Setters ----------------------------------------------
    public ArrayList<String> getStringList() {
        return stringList;
    }

    public ArrayList<Word> getWordList() {
        return wordList;
    }

    public void setList(ArrayList<String> list) {
        this.stringList = list;
    }

}