import java.util.ArrayList;
import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.FileReader;

public class cachesimulator {

    // declare our main public variables
    public static ArrayList<String> ram = new ArrayList<String>(256);
    public static ArrayList<ArrayList<String>> cache;
    
    // C
    public static int cacheSize;

    // B and b
    public static int blockSize;
    public static int numOffsetBits;

    // E
    public static int associativity;

    // S and s
    public static int numSets;
    public static int numSetBits;

    // m
    public static int physicalAddressBits = 8;

    // t
    public static int numTagBits;

    public static int replacementPolicy;
    public static int hitPolicy;
    public static int missPolicy;
    public static boolean quit = false;
    
    



    public static void main(String[] args) {
        String filename = args[0];
        Scanner s = new Scanner(System.in);
        // welcome and init RAM -------------------------------------
        //
        print("*** Welcome to the cache simulator ***");
        initRAM(filename);

        // init cache -----------------------------------------------
        //
        configCache(s);

        // simulate cache ---------------------------------
        //
        while (!quit) {

            // loop through our menu and selection functions
            String choice = viewMenu(s);
            doSelection(choice);
            

        }
    }


    // helper functions to make our main function cleaner
    
    // initialize our ram array
    public static void initRAM(String filename) {
        print("initialize the RAM:");
        print("init-ram 0x00 0xFF");
        
        
        Scanner infile;

            // get our ram values from input file
            try {
                infile = new Scanner(new FileReader(filename));

                // first populate ram array with "00"
                for (int i = 0; i < ram.size(); i++) {
                    ram.set(i, "00");
                }

                // then populate our ram array with input ram values
                while (infile.hasNextLine()) {
                    ram.add(infile.nextLine());
                }

                print("RAM successfully initialized!");

                // cleanup
                infile.close();

            // catch if file doesn't exist
            } catch (FileNotFoundException e) {
                print("Error: File not found!");
                e.printStackTrace();
            }
    }
    
    // config cache function
    public static void configCache(Scanner s) {
        print("configure the cache:");
        pront("cache size: ");
        cacheSize = s.nextInt(); 
        pront("data block size: "); 
        blockSize = s.nextInt(); 
        pront("associativity: ");
        associativity = s.nextInt(); 
        pront("replacement policy: ");
        replacementPolicy = s.nextInt(); 
        pront("write hit policy: ");
        hitPolicy = s.nextInt(); 
        pront("write miss policy: ");
        missPolicy = s.nextInt(); 

        // fill cache with 0s
        cacheFlush();

        numSets = (cacheSize / blockSize) / associativity;
        numSetBits = log2(numSets);
        numOffsetBits = log2(blockSize);
        numTagBits = physicalAddressBits - (numSetBits + numOffsetBits);
        // print("Tag bits: " + numTagBits);
        // print("m: " + physicalAddressBits);
        // print("s: " + numSetBits);
        // print("b: " + numOffsetBits);

        print("cache successfully configured!");

        // block = each list<String> in cache list: "0 0 00 00 00 00 00 00 00 00 00"
        // value = each String in list<String> in list: "0"
    }

    // view menu function
    public static String viewMenu(Scanner s) {
        
        print("*** Cache simulator menu ***");
        print("type one command:");
        print("1. cache-read");
        print("2. cache-write");
        print("3. cache-flush");
        print("4. cache-view");
        print("5. memory-view");
        print("6. cache-dump");
        print("7. memory-dump");
        print("8. quit");
        print("****************************");

        // clear buffer if not empty
        if (s.hasNextLine()) {
            s.nextLine();
        }
        
        return s.nextLine();
    }

    // choose from menu
    public static void doSelection(String choice) {
        
        // split our choice command string into command and args
        String[] selection = choice.split(" ");
        String command = selection[0];
        String[] arguments = new String[selection.length - 1];

        // fill in our arguments array
        if (selection.length > 1) {
            for (int i = 1; i < selection.length; i++) {
                arguments[i-1] = selection[i];
            }
        }
        
        // perform our task based on our command
        switch (command) {
            case "1", "cache-read":
                cacheRead(arguments); break;
            case "2", "cache-write":
                cacheWrite(arguments); break;
            case "3", "cache-flush":
                cacheFlush(); break;
            case "4", "cache-view":
                cacheView(); break;
            case "5", "memory-view":
                memoryView(); break;
            case "6", "cache-dump":
                cacheDump(); break;
            case "7", "memory-dump":
                memoryDump(); break;
            case "8", "quit":
                quit = true; break;
            
            default: 
                print("Invalid input [" + command + "], try again!"); break;
        }
    }

    // cache-read function
    public static void cacheRead(String[] arguments) {
        
        // get binary representation of hex input
        StringBuilder binAddr = new StringBuilder(Integer.toBinaryString(Integer.parseInt(arguments[0].substring(2), 16))); 
        
        // add leading zeroes
        for (int i = binAddr.length(); i < 8; i++) {
            binAddr.insert(0, "0");
        }
        
        print(binAddr.toString());
        int set = Integer.parseInt(binAddr.substring(numTagBits, numTagBits + numSetBits));
        String tag = binAddr.substring(0, numTagBits);
        print("set:" + set);
        print("tag:" + tag);
    }

    // cache-write function
    public static void cacheWrite(String[] arguments) {
        print(arguments[0]);
    }

    // cache-read function
    public static void cacheFlush() {
        cache = new ArrayList<ArrayList<String>>(0);
        // fill cache array with 00 using size
        for (int i = 0; i < cacheSize; i++) {
            ArrayList<String> tempString = new ArrayList<String>(0);
            tempString.add("0");
            tempString.add("0");
            tempString.add("00");
            tempString.add("00");
            tempString.add("00");
            tempString.add("00");
            tempString.add("00");
            tempString.add("00");
            tempString.add("00");
            tempString.add("00");
            tempString.add("00");
            cache.add(tempString);
        }
    }

    // cache-read function
    public static void cacheView() {
        
    }

    // cache-read function
    public static void memoryView() {
        
    }

    // cache-read function
    public static void cacheDump() {
        
    }

    // cache-read function
    public static void memoryDump() {
        
    }








    // log2 helper function
    public static int log2(int x) {  
        return (int)(Math.log(x) / Math.log(2));
    }

    // helper print functions
    public static void print(String input) {
        System.out.println(input);
    }
    public static void pront(String input) {
        System.out.print(input);
    }
}