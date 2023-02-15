/**
 * Elang.java
 * [Jelaskan kegunaan class ini]
 * @author [NIM] [Nama]
 */

 public class Elang extends Animal {

    private long basePower;
    private int jumlahTelur;

    public Elang(long basePower) {
        // Konstruktor, set jumlahTelur ke 0
    }

    public int getJumlahTelur(){
        // Mengembalikan atribut jumlahTelur
    }

    public void bertelur(){
        // Menambah jumlahTelur dengan 1
    }

    @Override
    public long getAnimalPower() {
        // Mengembalikan kekuatan Elang dengan formula basePower * children - jumlahTelur
    }
}
