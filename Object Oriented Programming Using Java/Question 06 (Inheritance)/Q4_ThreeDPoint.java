/*
Create a class named ThreeDPoint to model a point in a three-dimensional space. Let ThreeDPoint be derived from MyPoint 
with following additional features:

 i. A data elds named z that represents the z-coordinate.
 ii. A no-arg constructor that creates a point (0, 0, 0).
 iii. A constructor that constructs a point with three speci ed coordinates.
 iv. A get method that returns the z value.
 v. Override the distance method to return the distance between two points in the three-dimensional space.
 vi. Write a program that creates two points (0, 0, 0) and (10, 30, 25.5) and display the distance between the two points.
 */
public class Q4_ThreeDPoint extends Q4_MyPoint {
    private double z;

    // No-arg constructor that creates a point (0, 0, 0)
    public Q4_ThreeDPoint() {
        super();
        this.z = 0;
    }

    // Constructor that constructs a point with specified coordinates
    public Q4_ThreeDPoint(double x, double y, double z) {
        super(x, y);
        this.z = z;
    }

    // Getter method for z coordinate
    public double getZ() {
        return z;
    }

    // Override the distance method to calculate distance in 3D space
    @Override
    public double distance(Q4_MyPoint anotherPoint) {
        if (!(anotherPoint instanceof Q4_ThreeDPoint)) {
            throw new IllegalArgumentException("Argument must be a ThreeDPoint");
        }

        Q4_ThreeDPoint other = (Q4_ThreeDPoint) anotherPoint;
        double dx = this.x - other.x;
        double dy = this.y - other.y;
        double dz = this.z - other.z;
        return Math.sqrt(dx * dx + dy * dy + dz * dz);
    }

    // Main method to test the functionality
    public static void main(String[] args) {
        Q4_ThreeDPoint point1 = new Q4_ThreeDPoint();
        Q4_ThreeDPoint point2 = new Q4_ThreeDPoint(10, 30, 25.5);

        double distance = point1.distance(point2);

        System.out.println("Distance between the two points: " + distance);
    }
}
