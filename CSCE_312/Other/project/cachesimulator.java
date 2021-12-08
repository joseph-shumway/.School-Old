import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.FileReader;

public class cachesimulator {

    // declare our main public variables
    public static ArrayList<String> ram;
    public static ArrayList<ArrayList<ArrayList<String>>> cache;
    
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
        initRAM(filename, s);

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
    public static void initRAM(String filename, Scanner s) {
        
        String[] inLine;
        boolean getRamInit = false;
        String beginning = "";
        String end = "";


        // initialize RAM
        while (!getRamInit) {
            print("initialize the RAM:");
            inLine = s.nextLine().split(" ");
            if (inLine[0].equals("init-ram") && inLine.length == 3) {
                beginning = inLine[1];
                end = inLine[2];
                getRamInit = true;
            } else if (inLine[0].equals("asdf")){
                beginning = "0x00";
                end = "0xFF";
                getRamInit = true;
            } else {
                print("Invalid Input!");
            }
        }
        
        // create ram array based on beginning and end values
        ram = new ArrayList<String>(Integer.parseInt(end.substring(2), 16) - Integer.parseInt(beginning.substring(2), 16));
        
        
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
        s.nextLine();

        numSets = (cacheSize / blockSize) / associativity;
        numSetBits = log2(numSets);
        numOffsetBits = log2(blockSize);
        numTagBits = physicalAddressBits - (numSetBits + numOffsetBits);

        // fill cache with 0s
        cacheFlush();

        

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

        if (s.hasNextLine()) {
            return s.nextLine();
        } else {
            return "";
        }
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
        int position = 0;

        // get binary representation of hex input
        StringBuilder binAddr = new StringBuilder(Integer.toBinaryString(Integer.parseInt(arguments[0].substring(2), 16))); 
        
        // add leading zeroes
        for (int i = binAddr.length(); i < 8; i++) {
            binAddr.insert(0, "0");
        }
        
        // get set and tag
        print(binAddr.toString());
        int set = Integer.parseInt(binAddr.substring(numTagBits, numTagBits + numSetBits));
        String tag = binAddr.substring(0, numTagBits);

        String tagFromList = "";
        String tagFromInput = String.format("%02X", Integer.parseInt(tag, 2));

        // check if our value exists in our cache
        boolean hit = false;
        ArrayList<ArrayList<String>> setList = cache.get(set);
        int setOffset = 0;
        for (setOffset = 0; setOffset < setList.size(); setOffset++) {
            tagFromList = setList.get(setOffset).get(2);
            
            if (setList.get(setOffset).get(0).equals("1") && tagFromList.equals(tagFromInput)) {
                hit = true;
                break;
            }
        }

        // print out our values
        print("set:" + set);
        print("tag:" + tag);
        print("tagFromList:" + tagFromList);
        print("tagFromInput:" + tagFromInput);

        // eviction branches
        if (hit) {
            print("hit:yes");
            print("eviction_line:-1");

        } else {
            print("hit:no");

            // random replacement
            if (replacementPolicy == 1) {
                Random r = new Random();
                position = r.nextInt(associativity);
                print("eviction_line:" + position);

                // build our address for the beginning of our RAM block
                StringBuilder blockAddress = new StringBuilder(binAddr.substring(0, numTagBits + numSetBits));
                for (int i = 0; i < numOffsetBits; i++) {
                    blockAddress.append("0");
                }
                print("Block Address:" + blockAddress.toString());

                // convert address from binary to hex
                String blockAddressHex = String.format("%02X", Integer.parseInt(blockAddress.toString(), 2));
                print("Block Address:" + blockAddressHex);

                // convert address to decimal
                int blockAddressDec = Integer.parseInt(blockAddressHex, 16);
                print("Block Address:" + blockAddressDec);


                // add our block from ram into block array as well as valid and dirty bits
                ArrayList<String> blockFromRam = new ArrayList<String>(blockSize);
                blockFromRam.add("1");
                blockFromRam.add("0");

                // grab all pieces in block
                for (int i = 0; i < blockSize; i++) {
                    blockFromRam.add(ram.get(blockAddressDec + i));
                }

                print("RAM BLOCK: " + blockFromRam.toString());

                cache.get(set).set(position, blockFromRam);
                




            // Least Recently Used replacement
            } else if (replacementPolicy == 2) {

            }
        }
        
        print("Current Set: " + cache.get((set * associativity) + position).toString());

    }

    // cache-write function
    public static void cacheWrite(String[] arguments) {
        print(arguments[0]);
    }

    // cache-read function
    public static void cacheFlush() {
        cache = new ArrayList<ArrayList<ArrayList<String>>> (0);

        print("");
        // fill cache array with 00 using size
        for (int currentSet = 0; currentSet < ((cacheSize / blockSize) / associativity); currentSet++) {
            //print("currentSetIndex:" + currentSet);

            // add an empty Set to our cache first
            ArrayList<ArrayList<String>> emptySet = new ArrayList<ArrayList<String>> (0);
            cache.add(emptySet);

            for (int currentLine = 0; currentLine < associativity; currentLine++) {
                //print("currentLineIndex:" + currentLine);

                // add our empty block bits including Valid and Dirty bits
                ArrayList<String> tempBlock = new ArrayList<String>(0);
                tempBlock.add("0");
                tempBlock.add("0");
                for (int currentBlock = 0; currentBlock < blockSize; currentBlock++) {
                    tempBlock.add("00");
                }
                
                // add our block to our line
                cache.get(currentSet).add(tempBlock);
            }
            
        }

        // debug: print our empty cache
        int setCounter = 0;
        int lineCounter = 0;
        for (ArrayList<ArrayList<String>> set : cache) {
            print("-------------- [[set  " + setCounter++ + "]] --------------\n");
            for (ArrayList<String> line : set) {
                print("--------------- [line " + lineCounter++ + "] ---------------");
                print(line.toString() + "\n");
                
            }
            lineCounter = 0;
            print("\n");
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