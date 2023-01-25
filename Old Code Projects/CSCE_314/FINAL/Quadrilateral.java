import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;

public class Quadrilateral 
{

	Quadrilateral () {}
	Quadrilateral (Point a, Point b, Point c, Point d)
	{

		// *****************************************************
		//
		//	#6			#6			#6			#6
		//
		//
		// *****************************************************

		// can pretend the sides of the Quadrilateral do not cross

		ArrayList<Point> testArray = new ArrayList<Point>();
		testArray.add(a);
		testArray.add(b);
		testArray.add(c);
		testArray.add(d);

		// use same sort as from Driver
		Point origin = new Point(0, 0);
		int maximum = -100;
		int maxIndex = 0;
		ArrayList<Point> newList = new ArrayList<Point>();

		// sort our testArray
		while(!testArray.isEmpty()) {
			for (int j = 0; j < testArray.size(); j++) {
				if (origin.compareTo(testArray.get(j)) > maximum){
					maximum = origin.compareTo(testArray.get(j));
					maxIndex = j;
				}
			}
			maximum = -100;
			newList.add(testArray.get(maxIndex));
			testArray.remove(maxIndex);
		}
		testArray = newList;

		points = testArray;


	}

	
	private ArrayList <Point> points = new ArrayList<Point>(4);
	
	
	public String toString()
	{
		// *****************************************************
		//
		//	#7			#7			#7			#7
		//
		//
		// *****************************************************

		String value = "------------------------------ \n";
		// PLease place a "\n" after displaying each point
		for (Point point : points) {
			value += "X: " + point.getXPoint() + " " + "Y: " + point.getYPoint() + "\n";
		}
		
		return value;
	}
	
	
}
