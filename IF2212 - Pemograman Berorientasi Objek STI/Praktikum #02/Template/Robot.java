/**
 * Robot.java
 * [Jelaskan kegunaan class ini]
 * @author [NIM] [Nama]
 */

 public abstract class Robot {

    private int numberOfParts;
    private boolean isActive;

    public Robot(int numberOfParts, boolean isActive) {
        // Konstruktor
    }

    public int getNumberOfParts() {
        // Mengembalikan atribut numberOfParts
    }

    public boolean getIsActive() {
        // Mengembalikan atribut isActive
    }

    public void setActivation(boolean isActive) {
        // Menetapkan atribut isActive
    }

    public String toString() {
        // Mengembalikan informasi hewan dengan format: "Number of Parts: {numberOfParts}, IsActive: {isActive}"
    }

    public abstract long getPrice();
}
