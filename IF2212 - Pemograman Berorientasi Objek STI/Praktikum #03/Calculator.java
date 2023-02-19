/* Interface untuk kalkulator
 * @author Fawwaz Abrial Saffa 18221067 */

public interface Calculator {
	
	public int add (int a, int b);
	public int substract (int a, int b);
	public int multiply (int a, int b);
	public double divide (int a, int b);
	public void start ();
	public void stop ();
	public int checkBattery ();
}
