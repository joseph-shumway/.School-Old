import java.util.*;

class Numberline implements Comparator
{

	
	
	// Comparator interface requires defining comparison method.

	// *****************************************************
	//
	//	#8			#8			#8			#8
	//
	//
	// *****************************************************

	@Override
	public int compare(Object o1, Object o2) {
		if (o1 instanceof Point && o2 instanceof Point) {
			Point to1 = (Point) o1;
			Point to2 = (Point) o2;

			if (to1.getXPoint() < to2.getXPoint()) {
				return -1;
			}
			if (to1.getXPoint() > to2.getXPoint()) {
				return 1;
			}
		}
		return 0;
	}
}