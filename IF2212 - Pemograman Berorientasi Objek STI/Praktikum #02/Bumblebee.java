
/**
 * Bumblebee.java
 * Bumblebee merupakan turunan dari Robot
 * @author 18221067 Fawwaz Abrial Saffa
 */

public class Bumblebee extends Robot {

    private int totalTransformation;

    public Bumblebee(int numberOfParts, boolean isActive) {
        // Konstruktor, set totalTransformation = 1
        super(numberOfParts, isActive);
        totalTransformation = 1;
    }

    public int getTotalTransformation(){
        // Mengembalikan totalTransformation
        return totalTransformation;
    }

    public void addTransformation(){
        // Menambahkan totalTransformation sejumlah 1
        totalTransformation++;
    }

    @Override
    public long getPrice() {
        // Apabila aktif, harga bernilai numberOfParts * 1000 * totalTransformation
        // Apabila tidak aktif, harga bernilai numberOfParts * 1000
        if (getIsActive()) return getNumberOfParts() * 1000 * getTotalTransformation();
        else return getNumberOfParts() * 1000;
    }
}
