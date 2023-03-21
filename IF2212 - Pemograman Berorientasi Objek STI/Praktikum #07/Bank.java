public class Bank {
    /**
     * Tambahkan atribut kelas disini
     */ 
    String name;

    public Bank(String name) {
        /**
         * Konstruktor
         * Jangan lupa inisialisasi atribut kelas
         */ 
        this.name = name;
    }

    public void transfer(Account accountFrom, Account accountTo, int jumlah) throws Exception {
        /**
         * Implementasi
         * Transfer antar bank (akun dengan nama bank berbeda) akan dikenakan biaya admin sebesar 
         * 2500 yang dikurangi dari saldo pengirim. 
         * 
         * Biaya admin ini tidak ikut ditransfer ke akun tujuan. 
         * 
         * Apabila accountFrom memiliki nama bank yang tidak sama dengan bank yang melakukan transfer, 
         * lempar exception dengan pesan "Bukan akun milik bank {bankName}".
         */

         if (!(accountFrom.getBankName().equals(name))) throw new Exception("Bukan akun milik bank " + name);

         if (accountFrom.getBankName().equals(accountTo.getBankName())) {
            accountFrom.decreaseSaldo(jumlah);
         } else {
            accountFrom.decreaseSaldo(jumlah+2500);
         }

         accountTo.increaseSaldo(jumlah);
    }

    public Account createAccount(String accountName, int saldo) throws Exception {
        /**
         * Implementasi
         * Akun yang dibuat akan memiliki atribut bankName dengan nama bank yang membuat akun. 
         * Method ini akan melanjutkan pelemparan exception dari kelas Account.
         */
        try {
            return new Account(accountName, name, saldo);
        }
        catch (Exception e) {
            throw new Exception(e);
        }
    }
}
