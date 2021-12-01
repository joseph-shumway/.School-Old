import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class Hashing {
    

    private ArrayList<Word> wordList;
    private BST bst;

    public Hashing() {
        this.wordList = new ArrayList<Word>(0);
        this.bst = new BST();
    }

    public Hashing(ArrayList<Word> wl) {
        this.wordList = wl;
        this.bst = new BST();
    }







    // LIST methods ---------------------------------

    // write equal for LIST
    public void writeListEqual() {
        PrintWriter outfile;

        try {
            outfile = new PrintWriter("resultsListEqual.txt");
            
            // grab each word that has the same amt of occurences in both files and write to resultsListEqual.txt
            for (Word word : wordList) {
                if (word.getCountPT() == word.getCountYT()) {
                    String output = String.format("%-14s%8s%n", word.getValue(), word.getCountPT());
                    outfile.write(output);
                }
            }
            
            outfile.close();
        } catch (FileNotFoundException e) {
            System.out.println("Could not output to debug1.txt");
        }
    }

    // write difference for LIST
    public void writeListDifference() {
        PrintWriter outfile;
        StringBuilder outNum = new StringBuilder();

        try {
            outfile = new PrintWriter("resultsListDiff.txt");
            
            // grab each word that has different amt of occurences in both files and write to resultsListEqual.txt
            for (Word word : wordList) {
                if (word.getCountPT() != word.getCountYT()) {

                    // append the difference between occurences
                    if (word.getCountPT() > word.getCountYT()) {outNum.append("+" + String.valueOf(Math.abs(word.getCountYT() - word.getCountPT())) + " PT");}
                    if (word.getCountYT() > word.getCountPT()) {outNum.append("+" + String.valueOf(Math.abs(word.getCountYT() - word.getCountPT())) + " YT");}
                    

                    // output "- ZERO" if one of the occurences is 0
                    if (word.getCountYT() == 0 || word.getCountPT() == 0) {
                        outNum.append(" - ZERO");
                    }
                    String output = String.format("%-14s%-14s%n", word.getValue(), outNum);
                    outfile.write(output);

                    outNum.setLength(0);
                }
            }
            
            outfile.close();
        } catch (FileNotFoundException e) {
            System.out.println("Could not output to debug1.txt");
        }
    }

    // BST methods ----------------------------------

    // write equal for BST
    public void writeEqual() {
        PrintWriter outfile;
        
        for (Word word : wordList) {
            bst.insert(word);
        }

        


        try {
            outfile = new PrintWriter("resultsEqual.txt");
            
            // grab each word that has the same amt of occurences in both files and write to resultsEqual.txt
            writeEqualHelper(bst.getRoot(), outfile);
            
            outfile.close();
        } catch (FileNotFoundException e) {
            System.out.println("Could not output to debug1.txt");
        }
    }

    // helper recursive method for writeEqual()
    public void writeEqualHelper(BSTNode r, PrintWriter out) {
        if (r != null) {

            // print all Nodes that have equal PT and YT values inorder
            writeEqualHelper(r.getLeft(), out);
            if (r.getData().getCountPT() == r.getData().getCountYT()) {
                out.write(r.getData().getValue() + "\n");
            }
            
            writeEqualHelper(r.getRight(), out);
        }
    }

    // write difference for BST
    public void writeDifference() {

    }

    // helper recursive method for writeDifference()
    public void writeEqualHelper(BSTNode r, PrintWriter out) {
        if (r != null) {

            // print all Nodes that have equal PT and YT values inorder
            writeEqualHelper(r.getLeft(), out);
            if (r.getData().getCountPT() == r.getData().getCountYT()) {
                out.write(r.getData().getValue() + "\n");
            }
            
            writeEqualHelper(r.getRight(), out);
        }
    }

}
