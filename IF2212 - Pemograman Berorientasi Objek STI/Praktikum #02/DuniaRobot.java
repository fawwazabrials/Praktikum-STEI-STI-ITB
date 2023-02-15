import java.util.Scanner;

public class DuniaRobot {
    public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int kode = scan.nextInt();
		if (kode == 1) {
			int numberOfParts = scan.nextInt();
			int totalTransformation = scan.nextInt();
			boolean isActive = scan.nextBoolean();
			
			Bumblebee r = new Bumblebee(numberOfParts, isActive);
			
			System.out.println(r.toString());

			for (int i=0; i<totalTransformation; i++) r.addTransformation();
			System.out.println("Jumlah transformasi: " + r.getTotalTransformation());
			
			System.out.println("Harga robot: " + r.getPrice());
		}
		
		if (kode == 2) {
			int price = scan.nextInt();
			int totalModel = scan.nextInt();
			
			Sirik r = new Sirik(price);
			
			System.out.println(r.toString());

			for (int i=0; i<totalModel; i++) r.addModel();
			System.out.println("Jumlah model: " + r.getTotalModel());
			
			System.out.println("Harga robot: " + r.getPrice());
		}
		
		if (kode == 3) {
			int mileage = scan.nextInt();
			boolean isActive = scan.nextBoolean();
			
			WallE r = new WallE(mileage, isActive);
			
			System.out.println(r.toString());

			System.out.println("Jumlah mileage: " + r.getMileage());
			
			System.out.println("Harga robot: " + r.getPrice());
		}
	}
}

