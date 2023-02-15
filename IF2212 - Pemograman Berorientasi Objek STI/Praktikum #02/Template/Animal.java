/**
 * Animal.java
 * [Jelaskan kegunaan class ini]
 * @author [NIM] [Nama]
 */

public abstract class Animal {

    private int numberOfLegs;
    private long children;

    public Animal(int numberOfLegs) {
        // Konstruktor, set children = 0
    }

    public int getNumberOfLegs() {
        // Mengembalikan atribut numberOfLegs
    }

    public long getNumberOfChildren() {
        // Mengembalikan atribut children
    }

    public void increaseChild(long inc) {
        // Meningkatkan nilai atribut children
    }

    public String toString() {
        // Mengembalikan informasi hewan dengan format: "Number of Legs: {numberOfLegs}, Children: {children}"
    }

    public abstract long getAnimalPower();
}
