import java.io.FileNotFoundException;
import java.io.PrintWriter;

public class Testing {
    
    public void findStat(Word w) {
        PrintWriter outfile;

        try {
            outfile = new PrintWriter("statResults.txt");
            
            
            
            outfile.close();
        } catch (FileNotFoundException e) {
            System.out.println("Could not output to debug1.txt");
        }
    }
}
