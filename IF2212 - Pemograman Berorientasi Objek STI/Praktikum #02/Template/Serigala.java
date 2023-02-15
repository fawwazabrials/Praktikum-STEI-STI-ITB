/**
 * Serigala.java
 * [Jelaskan kegunaan class ini]
 * @author [NIM] [Nama]
 */

 public class Serigala extends Animal {

    private long basePower;
    private boolean kawanan;

    public Serigala(long basePower, boolean kawanan) {
        // Konstruktor
    }

    private boolean hasKawanan(){
        // Mengembalikan state apakah ia memiliki kawanan atau tidak
    }

    @Override
    public long getAnimalPower() {
        // Mengembalikan kekuatan serigala.
        // Apabila ia memiliki kawanan dan anak, formulanya basePower * 3 * children
        // Selain itu, kekuatan hanya bernilai basePower
    }
}
