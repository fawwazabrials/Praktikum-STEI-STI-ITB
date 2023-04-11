import java.util.*;
import java.lang.*;
import java.lang.reflect.Method;

public class Main {
    // public static List<String> findCommonElements(List<String> list1, List<String> list2) {
    //     ArrayList<String> res = new ArrayList<String>();
        
    //     TreeSet<String> S1 = new TreeSet<String>(list1);
    //     TreeSet<String> S2 = new TreeSet<String>(list2);

    //     for (String str : S1) {
    //         if (S2.contains(str)) {
    //             res.add(str);
    //         }
    //     }

    //     return res;
    // }

    public static void main(String[] args) {
    //     Scanner scan = new Scanner(System.in);
    
    //     ArrayList<String> l1 = new ArrayList<String> ();
    //     ArrayList<String> l2 = new ArrayList<String> ();

    //     for (String str : scan.nextLine().split(" ")) {
    //         l1.add(str);
    //     }
    //     for (String str : scan.nextLine().split(" ")) {
    //         l2.add(str);
    //     }

    //     System.out.println(findCommonElements(l1, l2));

    // }

    Class c = Map.class;
    Method m[] = c.getMethods();
    for (Method e: m) {
        System.out.println(e.getName());
}   }
}
