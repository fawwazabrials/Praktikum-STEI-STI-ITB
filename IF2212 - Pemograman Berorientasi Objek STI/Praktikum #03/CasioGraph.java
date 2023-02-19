/* Kelas untuk kalkulator Casio yang bisa graph dengan 
 * mengimplementasikaninterface GraphCalculator
 * @author Fawwaz Abrial Saffa 18221067 */
 
 public class CasioGraph implements GraphCalculator{
	Point point;
	int batteryLevel = 100;
	boolean status = false;
	
	public CasioGraph (int x, int y) {
		point = new Point(x, y);
	}
	
	@Override
	public void start () {
		if (checkBattery() > 0) status = true;
	}
	
	@Override
	public void stop () {
		status = false;
	}
	
	public void charge () {
		batteryLevel = 100;
	}
	
	public Point getPoint () {
		return point;
	}
	
	@Override
	public int checkBattery () {
		return batteryLevel;
	}
	
	public boolean getStatus () {
		return status;
	}
	
	@Override
	public int add (int a, int b) {
		if (status) {
			batteryLevel -= 10;
			if (checkBattery() <= 0) status = false;
			return a+b;
		} else return -1;
	}
	
	@Override
	public int substract (int a, int b) {
		if (status) {
			batteryLevel -= 10;
			if (checkBattery() <= 0) status = false;
			return a-b;
		} else return -1;
	}
	
	@Override
	public int multiply (int a, int b) {
		if (status) {
			batteryLevel -= 10;
			if (checkBattery() <= 0) status = false;
			return a * b;
		} else return -1;
	}
	
	@Override
	public double divide (int a, int b) {
		if (status) {
			batteryLevel -= 10;
			if (checkBattery() <= 0) status = false;
			return a / b;
		} else return -1;
	}
	
	@Override
	public void shiftX (int shiftCount) {
		if (status) {
			point.setX((point.getX() + shiftCount));
			batteryLevel -= 10;
			if (checkBattery() <= 0) status = false;
		} 
	}
	
	@Override
	public void shiftY (int shiftCount) {
		if (status) {
			point.setY((point.getY() + shiftCount));
			batteryLevel -= 10;
			if (checkBattery() <= 0) status = false;
		}
	}
	
	@Override
	public double distance (int x, int y) {
		if (status) {
			batteryLevel -= 10;
			if (checkBattery() <= 0) status = false;
			return Math.sqrt(Math.pow((point.getX() - x), 2) + Math.pow((point.getY() - y), 2));
		} else return -1;
	} 
}
