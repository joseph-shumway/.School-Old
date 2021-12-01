public class Word {
    
    private String value;
    private int countPT;
    private int countYT;

    // Constructors ----------------------------------------------
    public Word(String value, int countPT, int countYT) {
        this.value = value;
        this.countPT = countPT;
        this.countYT = countYT;
    }

    public Word(Word w) {
        this.value = w.value;
        this.countPT = w.countPT;
        this.countYT = w.countYT;
    }


    // toString method -----------------------------------------
    @Override
    public String toString() {
        return "---------- " + value + " " + countPT + " " + countYT + "\n";
    }

    // Comparator method
    public int compareTo(Word word2) {
        return this.value.compareTo(word2.value);
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
