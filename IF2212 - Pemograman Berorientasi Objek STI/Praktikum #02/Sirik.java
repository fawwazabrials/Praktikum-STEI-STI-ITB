/**
 * Sirik.java
 * Sirik merupakan turunan dari Robot
 * @author 18221067 Fawwaz Abrial Saffa
 */

public class Sirik extends Robot {

    private long price;
    private int totalModel;

    public Sirik(long price) {
		super(5, false);
        this.price = price;
        totalModel = 1;
    }

    public int getTotalModel(){
        return totalModel;
    }

    public void addModel(){
        totalModel++;
    }

    @Override
    public long getPrice() {
		// Apabila total model lebih dari/samadengan 2, 
        // maka formula = price + (500 * numberOfParts - (100 * totalModel))
        // Apabila total model kurang dari/sama dengan 2,
        // maka formula = price + (500 * numberOfParts * totalModel)
		if (totalModel > 2) return price + (500 * getNumberOfParts() - (100 * getTotalModel()));
		else return price + (500 * getNumberOfParts() * getTotalModel());
    }
}
