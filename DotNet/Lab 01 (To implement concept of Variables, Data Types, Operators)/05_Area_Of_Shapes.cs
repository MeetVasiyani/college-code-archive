/* 5. (A) Write a program to calculate area of Square, Rectangle and Circle. */

Console.WriteLine("Enter 1 for Square\nEnter 2 for Rectangle\nEnter 3 for Circle");
int temp = Convert.ToInt32(Console.ReadLine());

switch (temp)
{
    case 1:
        Console.WriteLine("Enter side of square : ");
        double side = Convert.ToDouble(Console.ReadLine());
        double area = side * side;
        Console.WriteLine($"Area of square : {area}");
        break;
    case 2:
        Console.WriteLine("Enter length of rectangle : ");
        double length = Convert.ToDouble(Console.ReadLine());
        Console.WriteLine("Enter width of rectangle : ");
        double width = Convert.ToDouble(Console.ReadLine());
        double area1 = length * width;
        Console.WriteLine($"Area of rectangle : {area1}");
        break;
    case 3:
        Console.WriteLine("Enter radius of circle : ");
        double radius = Convert.ToDouble(Console.ReadLine());
        double area2 = 3.14 * radius * radius;
        Console.WriteLine($"Area of circle : {area2}");
        break;
    default:
        Console.WriteLine("Invalid input");
        break;
}