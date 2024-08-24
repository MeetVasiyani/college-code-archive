/* 
Design a class named MyPoint to represent a point with x and y-coordinates. The class contains:
 
 i. The data elds x and y that represent the coordinates with getter methods.
 ii. A no-arg constructor that creates a point (0, 0).
 iii. A constructor that constructs a point with speci ed coordinates.
 iv. A method named distance that returns the distance from this point to a speci ed point of the MyPoint type.
 v. A method named distance that returns the distance from this point to another point with speci ed x- and y
    coordinates. 
*/
public class Q4_MyPoint {
    protected double x;
    protected double y;

    // No-arg constructor that creates a point (0, 0)
    public Q4_MyPoint() {
        this.x = 0;
        this.y = 0;
    }

    // Constructor that constructs a point with specified coordinates
    public Q4_MyPoint(double x, double y) {
        this.x = x;
        this.y = y;
    }

    // Getter methods for x and y coordinates
    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    // Method to calculate the distance from this point to a specified point of the MyPoint type
    public double distance(Q4_MyPoint anotherPoint) {
        double dx = this.x - anotherPoint.x;
        double dy = this.y - anotherPoint.y;
        return Math.sqrt(dx * dx + dy * dy);
    }

    // Method to calculate the distance from this point to another point with specified x- and y-coordinates
    public double distance(double x, double y) {
        double dx = this.x - x;
        double dy = this.y - y;
        return Math.sqrt(dx * dx + dy * dy);
    }
}



