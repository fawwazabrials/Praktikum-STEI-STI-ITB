import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);

        String user;
        user = scan.next();

        Email email = new Email(user);
        boolean result = false;

        try {
        	result = email.validateEmail();
        }

        catch (Exception e) {
        	System.out.println(e.getClass().getSimpleName() + "! " + e.getMessage());
        	System.out.println("Email string error!");
        }

        if (result) System.out.println(result + "\nEmail validated.");
        System.out.println("Operation finished.");
        
        scan.close();
    }
    
}
