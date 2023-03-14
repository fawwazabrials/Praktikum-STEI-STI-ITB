import java.lang.System;
import java.util.ArrayList;
import java.util.List;


public class RobotPrinter {
    // Hint 1:
    // List adalah interface Java yang merupakan subinterface dari interface Collection
    // Deklarasi tipe generic `List` di Java yang sudah tersedia adalah:
    // `public interface List<E> extends Collection<E>`
    // 
    // Seperti dapat dilihat, List bisa menggunakan variabel tipe (T) generic saat digunakan. Contoh penggunaannya:
    // List<Integer> integerList = ...;   

    // Hint 2:
    // Iterasi melalui seluruh elemen list dapat digunakan dengan loop for-each, yang di Java bisa dilakukan dengan sintaks:
    // for (E element : elementList){
        //operasi pada element
    // }

    public void printListOfRobot(List<? extends Robot> l) {
        for (Robot thing : l) {
            System.out.println(thing.getName());
        }
    }

    public void printListOfTransformer(List<? extends Transformer> l) {
        for (Transformer thing : l) {
            System.out.println(thing.getWeapons());
        }
    }

    public void printClassNameOfList(List<? extends Object> l) {
        for (Object thing : l) {
            System.out.println(thing.getClass().getName());
        }
    }

    public <U> void printObjectClassName (U thing) {
        System.out.println(thing.getClass().getName());
    }

}

class Robot {
    private String name;
  
    public Robot(String name) {
        this.name = name;
    }

    public String getName(){
        return this.name;
    }
}

class Transformer extends Robot{
    private int weapons;
    public Transformer(String name, int weapons){
        super(name);
        this.weapons = weapons;
    }

    public int getWeapons(){
        return this.weapons;
    }
}

class Bumblebee extends Transformer{
    public Bumblebee(String name, int weapons){
        super(name,weapons);
    }
}

class Baymax extends Robot{
    public Baymax(String name){
        super(name);
    }
}
