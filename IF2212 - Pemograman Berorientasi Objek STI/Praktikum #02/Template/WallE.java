/**
 * WallE.java
 * [Jelaskan kegunaan class ini]
 * @author [NIM] [Nama]
 */

 public class WallE extends Robot {

    private long mileage;

    public WallE(long mileage, boolean isActive) {
        // Konstruktor
    }

    public long getMileage(){
        // Mengembalikan mileage
    }

    public void addMileage(long increment){
        // Menambahkan mileage dengan increment
    }

    @Override
    public long getPrice() {
        // Apabila sedang aktif, maka harga total adalah mileage * 1000, 
        // Apabila tidak aktif maka ada tambahan biaya 500
    }
}
