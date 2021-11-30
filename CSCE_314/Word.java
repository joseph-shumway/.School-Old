public class Word {
    
    private String value;
    private int countPT;
    private int countYT;

    // Constructor ----------------------------------------------
    public Word(String value, int countPT, int countYT) {
        this.value = value;
        this.countPT = countPT;
        this.countYT = countYT;
    }


    // toString function -----------------------------------------
    @Override
    public String toString() {
        return "---------- " + value + " " + countPT + " " + countYT + "\n";
    }


    // Getters and Setters ----------------------------------------
    public String getValue() {
        return value;
    }
    public void setValue(String value) {
        this.value = value;
    }
    public int getCountPT() {
        return countPT;
    }
    public void setCountPT(int countPT) {
        this.countPT = countPT;
    }
    public int getCountYT() {
        return countYT;
    }
    public void setCountYT(int countYT) {
        this.countYT = countYT;
    }

}
