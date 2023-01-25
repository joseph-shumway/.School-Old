import java.util.ArrayList;

class Point /* implements Comparable<Point>   */
{

	private float xPoint;
	private float yPoint;

	// constructors
	Point() {}
	Point( float newX, float newY) { xPoint = newX; yPoint = newY; }

	// accessors/getters
	public float getXPoint() { return xPoint; }
	public float getYPoint() { return yPoint; }        

	// mutators/setters
	public void setXPoint(float newX) { xPoint = newX; }
	public void setYPoint(float newY) { yPoint = newY; }        

	public int compareTo(Point newPT)
	{

		// if compared (and printed) left to right, top to bottom in increasing value fashion
		// use the chart to help provide what the results should be
		
		// testing compare
		// *****************************************************
		//
		//	#1			#1			#1			#1
		//
		//
		// *****************************************************

		// conditions for compareTo
		if (xPoint - newPT.xPoint > 0 && yPoint == newPT.yPoint) {return 1;}     // same horiz line, left of
		if (xPoint - newPT.xPoint < 0 && yPoint == newPT.yPoint) {return -1;}    // same horiz line, right of
		if (xPoint == newPT.xPoint && yPoint - newPT.yPoint > 0) {return -3;}    // same vert  line, below
		if (xPoint == newPT.xPoint && yPoint - newPT.yPoint < 0) {return 3;}     // samve vert line, above
		if (xPoint - newPT.xPoint < 0 && yPoint - newPT.yPoint < 0) {return 2;}  // diagonally top right
		if (xPoint - newPT.xPoint < 0 && yPoint - newPT.yPoint > 0) {return -4;} // diagonally bottom right
		if (xPoint - newPT.xPoint > 0 && yPoint - newPT.yPoint < 0) {return 4;}  // diagonally top left 
		if (xPoint - newPT.xPoint > 0 && yPoint - newPT.yPoint > 0) {return -2;}  // diagonally bottom left
		if (xPoint == newPT.xPoint && yPoint == newPT.yPoint) {return 0;}

		return 0;
		
	}
	
	public boolean equals(Point newPT)
	{
		// *****************************************************
		//
		//	#2			#2			#2			#2
		//
		//
		// *****************************************************	

		if (xPoint == newPT.xPoint && yPoint == newPT.yPoint) {return true;}

		return false;
	}

	// toString
	public String toString() { return "X: " + getXPoint() + "\t\tY: " + getYPoint(); }

	// other methods
	public int getQuadrant() 
	{
		// *****************************************************
		//
		//	#3			#3			#3			#3
		//
		//
		// *****************************************************
		Point origin = new Point(0, 0);
		int directionNumber = origin.compareTo(this);

		//System.out.println( "Direction Num: " + directionNumber);

		switch (directionNumber) {
			case 0,1,-1,3,-3: return 0;
			case 2: return 1;
			case 4: return 2;
			case -2: return 3;
			case -4: return 4;
			default: break;
		}
		
		return 0;
	}




}