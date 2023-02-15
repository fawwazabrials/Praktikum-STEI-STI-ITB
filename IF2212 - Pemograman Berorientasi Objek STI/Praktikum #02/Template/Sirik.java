/**
 * Sirik.java
 * [Jelaskan kegunaan class ini]
 * @author [NIM] [Nama]
 */

 public class Sirik extends Robot {

    private long price;
    private int totalModel;

    public Sirik(long price) {
        // Konstruktor, set jumlah model bernilai 1
    }

    public int getTotalModel(){
        // Mengembalikan junlah
    }

    public void addModel(){
        // Menambahkan model sejumlah 1
    }

    @Override
    public long getPrice() {
        // Apabila total model lebih dari 2, 
        // maka formula = price + (500 * numberOfParts - (100 * totalModel))
        // Apabila total model kurang dari/sama dengan 2,
        // maka formula = price + (500 * numberOfParts * totalModel)
    }
}
