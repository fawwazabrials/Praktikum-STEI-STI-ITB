/**
 * Robot.java
 * Kelas ini adalah pemodelan sebuah robot di dunia nyata.
 * Kelas ini diperuntukan sebagai sebuah parent class dari
 * turunan-turunan robot hewan
 * @author 18221067 Fawwaz Abrial Saffa
 */

public abstract class Robot {

    private int numberOfParts;
    private boolean isActive;

    public Robot(int numberOfParts, boolean isActive) {
        this.numberOfParts = numberOfParts;
        this.isActive = isActive;
    }

    public int getNumberOfParts() {
        return numberOfParts;
    }

    public boolean getIsActive() {
        return isActive;
    }

    public void setActivation(boolean isActive) {
        this.isActive = isActive;
    }

    public String toString() {
        return ("Number of Parts: " + getNumberOfParts() + ", IsActive: "+ getIsActive());
    }

    public abstract long getPrice();
}
