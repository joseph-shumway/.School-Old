import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;

public class Hashing {
    

    private ArrayList<Word> wordList;
    private HashMap<String, BST> buckets;

    public Hashing() {
        this.wordList = new ArrayList<Word>(0);
        this.buckets = new HashMap<String, BST>(26);
        setupBuckets();
        fillBuckets();
    }

    public Hashing(ArrayList<Word> wl) {
        this.wordList = wl;
        this.buckets = new HashMap<String, BST>(26);
        setupBuckets();
        fillBuckets();
    }

    // setup buckets with a BST for each letter
    public void setupBuckets() {
        buckets.put("a", new BST());
        buckets.put("b", new BST());
        buckets.put("c", new BST());
        buckets.put("d", new BST());
        buckets.put("e", new BST());
        buckets.put("f", new BST());
        buckets.put("g", new BST());
        buckets.put("h", new BST());
        buckets.put("i", new BST());
        buckets.put("j", new BST());
        buckets.put("k", new BST());
        buckets.put("l", new BST());
        buckets.put("m", new BST());
        buckets.put("n", new BST());
        buckets.put("o", new BST());
        buckets.put("p", new BST());
        buckets.put("q", new BST());
        buckets.put("r", new BST());
        buckets.put("s", new BST());
        buckets.put("t", new BST());
        buckets.put("u", new BST());
        buckets.put("v", new BST());
        buckets.put("w", new BST());
        buckets.put("x", new BST());
        buckets.put("y", new BST());
        buckets.put("z", new BST());
    }

    // fill buckets with values in wordList
    public void fillBuckets() {
        // insert all words into their buckets
        for (Word word : wordList) {
            switch (word.getValue().charAt(0)) {
                case 'a': buckets.get("a").insert(word); continue;
                case 'b': buckets.get("b").insert(word); continue;
                case 'c': buckets.get("c").insert(word); continue;
                case 'd': buckets.get("d").insert(word); continue;
                case 'e': buckets.get("e").insert(word); continue;
                case 'f': buckets.get("f").insert(word); continue;
                case 'g': buckets.get("g").insert(word); continue;
                case 'h': buckets.get("h").insert(word); continue;
                case 'i': buckets.get("i").insert(word); continue;
                case 'j': buckets.get("j").insert(word); continue;
                case 'k': buckets.get("k").insert(word); continue;
                case 'l': buckets.get("l").insert(word); continue;
                case 'm': buckets.get("m").insert(word); continue;
                case 'n': buckets.get("n").insert(word); continue;
                case 'o': buckets.get("o").insert(word); continue;
                case 'p': buckets.get("p").insert(word); continue;
                case 'q': buckets.get("q").insert(word); continue;
                case 'r': buckets.get("r").insert(word); continue;
                case 's': buckets.get("s").insert(word); continue;
                case 't': buckets.get("t").insert(word); continue;
                case 'u': buckets.get("u").insert(word); continue;
                case 'v': buckets.get("v").insert(word); continue;
                case 'w': buckets.get("w").insert(word); continue;
                case 'x': buckets.get("x").insert(word); continue;
                case 'y': buckets.get("y").insert(word); continue;
                case 'z': buckets.get("z").insert(word); continue;
                default: continue;
            }
            
        }
    }


    // LIST methods ---------------------------------
    //
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
    //
    // write equal for BST
    public void writeEqual() {
        PrintWriter outfile;

        try {
            outfile = new PrintWriter("resultsEqual.txt");
            BST currentTree;
            
            // first grab our tree for each letter, then grab each word that has the same amt of occurences in both files and write to resultsEqual.txt
            currentTree = buckets.get("a");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("b");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("c");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("d");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("e");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("f");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("g");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("h");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("i");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("j");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("k");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("l");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("m");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("n");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("o");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("p");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("q");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("r");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("s");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("t");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("u");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("v");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("w");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("x");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("y");
            writeEqualHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("z");
            writeEqualHelper(currentTree.getRoot(), outfile);
            
            // close our file
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
        PrintWriter outfile;
        
        try {
            outfile = new PrintWriter("resultsDiff.txt");
            BST currentTree;
                
            // first grab our tree for each letter, then grab each word that has different amt of occurences in both files and write to resultsDiff.txt
            currentTree = buckets.get("a");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("b");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("c");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("d");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("e");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("f");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("g");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("h");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("i");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("j");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("k");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("l");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("m");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("n");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("o");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("p");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("q");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("r");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("s");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("t");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("u");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("v");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("w");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("x");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("y");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            currentTree = buckets.get("z");
            writeDifferenceHelper(currentTree.getRoot(), outfile);
            
            outfile.close();
        } catch (FileNotFoundException e) {
            System.out.println("Could not output to resultsDiff.txt");
        }
    }

    // helper recursive method for writeDifference()
    public void writeDifferenceHelper(BSTNode r, PrintWriter out) {
        StringBuilder outNum = new StringBuilder();
        
        if (r != null) {

            // print all Nodes that have equal PT and YT values inorder
            writeDifferenceHelper(r.getLeft(), out);

            if (r.getData().getCountPT() != r.getData().getCountYT()) {

                // append the difference between occurences
                if (r.getData().getCountPT() > r.getData().getCountYT()) {outNum.append("+" + String.valueOf(Math.abs(r.getData().getCountYT() - r.getData().getCountPT())) + " PT");}
                if (r.getData().getCountYT() > r.getData().getCountPT()) {outNum.append("+" + String.valueOf(Math.abs(r.getData().getCountYT() - r.getData().getCountPT())) + " YT");}
                

                // output "- ZERO" if one of the occurences is 0
                if (r.getData().getCountYT() == 0 || r.getData().getCountPT() == 0) {
                    outNum.append(" - ZERO");
                }

                String output = String.format("%-14s%-14s%n", r.getData().getValue(), outNum);
                out.write(output);

                outNum.setLength(0);
            }

            if (r.getData().getCountPT() != r.getData().getCountYT()) {
                out.write(r.getData().getValue() + "\n");
            }
            
            writeDifferenceHelper(r.getRight(), out);
        }
    }

}
