public class Email {
    private String email; 
    public Email(String email) {
        this.email = email;
    };
    
    public boolean validateEmail() throws InvalidEmailException, InvalidDomainException {
        /**
         * Implementasi dengan aturan:
         * Aturan email
         * - Email harus mengandung tepat 1 karakter @ ditengah email
         * - Bagian sebelum @ tidak boleh kosong
         * - Bagian email setelah @ harus memiliki tepat 1 buah titik (.)
         * - Email hanya akan mengandung huruf, angka, (@), dan (.). Karakter lain tidak
         * perlu diperiksa
         * 
         * "john@example.com" => Email Valid
         * "jane.doe@gmail.com" => Email Valid
         * "" => mengembalikan pesan "Email tidak boleh kosong"
         * "example.com" => mengembalikan pesan "Email harus mengandung tepat satu buah @"
         * "@example.com" => mengembalikan pesan "@ tidak boleh di awal email"
         * "john@com" => mengembalikan pesan "Email harus memiliki domain yang valid"
         */

        if (email.equals("")) throw new InvalidEmailException("Email tidak boleh kosong");

        int numSiput = 0;
        for (int i=0; i<email.length(); i++) {
            if (email.charAt(i) == '@') numSiput++;
        }
        if (numSiput != 1) throw new InvalidEmailException("Email harus mengandung tepat satu buah @");

        String[] pisah = email.split("@");

        if (email.charAt(0) == '@') throw new InvalidEmailException("@ tidak boleh di awal email");

        int numTitik = 0;
        for (int i=0; i<pisah[1].length(); i++) {
            if (pisah[1].charAt(i) == '.') numTitik++;
        }

        if ((numTitik != 1) ||
            (pisah[1].charAt(0) == '.') || 
            (pisah[1].charAt(pisah[1].length()-1) == '.')) 
                throw new InvalidDomainException();

        return true;

    }

}

class InvalidEmailException extends Exception {
    String message;

    public InvalidEmailException(String message) {
        // Implementasi InvalidEmailException
        this.message = message;
    }

    public String getMessage() {
        return message;
    }
}

class InvalidDomainException extends Exception {
    public String getMessage() {
        // Implementasi custom message InvalidDomainException
        // Return pesan multak berisi: "Email harus memiliki domain yang valid

        return "Email harus memiliki domain yang valid";
    }
}