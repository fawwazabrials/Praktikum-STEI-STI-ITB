import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        TreeSet<Integer> S = new TreeSet<Integer>();

        int t = scan.nextInt();
        for (int i=0; i<t; i++) {
            String req = scan.next();
            if (req.equals("add")) {
                int x = scan.nextInt();
                S.add(x);
            }
            if (req.equals("remove")) {
                int x = scan.nextInt();
                if (S.contains(x)) {
                    S.remove(x);
                } else {
                    System.out.println("Element "+ x +" is not in The TreeSet");
                }
            }
            if (req.equals("first")) {
                if (S.isEmpty()) System.out.println("EMPTY");
                else System.out.println(S.first());
            }
            if (req.equals("last")) {
                if (S.isEmpty()) System.out.println("EMPTY");
                else System.out.println(S.last());

            }
        }
    }
}