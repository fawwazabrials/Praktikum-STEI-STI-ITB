/**
 * Gajah.java
 * [Jelaskan kegunaan class ini]
 * @author [NIM] [Nama]
 */

 public class Gajah extends Animal {

    private long basePower;
    private long jumlahGading;

    public Gajah(long basePower, int jumlahGading) {
        // Konstruktor, jumlah gading minimal 0 maksimal 2
    }

    public long getJumlahGading(){
        // Mengembalikan jumlahGading
    }

    @Override
    public long getAnimalPower() {
        // Mengembalikan kekuatan Gajah dengan formula 3 * basePower * (1 + jumlahGading)
    }
}
