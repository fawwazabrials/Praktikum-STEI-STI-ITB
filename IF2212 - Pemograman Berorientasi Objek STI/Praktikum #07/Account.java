/**
 * Jangan lupa tambahkan kata kunci untuk menghandle exception
 */ 

public class Account {
    /**
     * Tambahkan atribut kelas disini
     */ 
    String name;
    String bankName;
    int saldo;


    public Account(String name, String bankName, int saldo) throws Exception {
        /**
         * Konstruktor
         * Jangan lupa inisialisasi atribut kelas
         */ 
        setName(name);
        this.bankName = bankName;

        if (saldo < 0) throw new Exception("Tidak dapat membuat akun dengan saldo dibawah 0");

        this.saldo = saldo;
    }

    public String getBankName() {
        /**
         * Implementasi
         * Return bankName
         */ 
        return bankName;
    }

    public String getName() {
        /**
         * Implementasi
         * Return name
         */ 
        return name;
    }
    
    public void setName(String name) throws Exception {
        /**
         * Implementasi
         * Ubah name
         * 
         * Sebuah name memiliki ketentuan yaitu memiliki panjang minimal 3 karakter. 
         * Apabila tidak memenuhi ketentuan ini, 
         * akan dilempar sebuah exception dengan pesan "Nama akun harus memiliki panjang minimal 3 karakter".
         */ 
        if (name.length() < 3) throw new Exception("Nama akun harus memiliki panjang minimal 3 karakter");
        this.name = name;
    }

    public int getSaldo() {
        /**
         * Implementasi
         * Return saldo
         */ 
        return saldo;
    }

    public void decreaseSaldo(int jumlah) throws Exception {
        /**
         * Implementasi
         * Kurangi jumlah saldo
         * 
         * Apabila jumlah saldo tidak mencukupi untuk melakukan operasi, 
         * dilemparkan exception dengan pesan "Saldo tidak mencukupi". 
         * 
         * Apabila parameter jumlah kurang dari 0, 
         * lempar exception dengan pesan "Jumlah pengurangan tidak boleh minus".
         */ 
        if (jumlah > getSaldo()) throw new Exception("Saldo tidak mencukupi");
        if (jumlah < 0) throw new Exception("Jumlah pengurangan tidak boleh minus");

        saldo -= jumlah;
    }

    public void increaseSaldo(int jumlah) throws Exception {
        /**
         * Implementasi
         * Tambahi saldo
         * 
         * Apabila parameter jumlah kurang dari 0, 
         * lempar exception dengan pesan "Jumlah penambahan tidak boleh minus".
         */

         if (jumlah < 0) throw new Exception("Jumlah penambahan tidak boleh minus");

         saldo += jumlah; 
    }
}
