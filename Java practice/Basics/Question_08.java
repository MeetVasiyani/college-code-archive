import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter hour hand sign : ");
        int h = sc.nextInt();
        
        System.out.println("Enter minute hand sign : ");
        int m = sc.nextInt();

        double angle = Math.abs(30*h - 5.5*m);

        angle = angle > 180 ? 360 - angle : angle;

        System.out.println("Angle between hands : "+angle);
    }
}