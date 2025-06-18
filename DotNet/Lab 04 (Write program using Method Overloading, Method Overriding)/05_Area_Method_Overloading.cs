/* 2.(A) Write a program using method overloading by changing number of arguments to calculate area of square and rectangle.*/
using System;

class Area_Method_Overloading
{
    
    public static int Area(int side)
    {
        return side * side;
    }
    public static int Area(int length, int width)
    {
        return length * width;
    }
    public static double Area(double radius)
    {
        return 3.14 * radius * radius;
    }

    public static void Main(string[] args)
    {
        Console.WriteLine("Area of Square: " + Area(5));
        Console.WriteLine("Area of Rectangle: " + Area(4, 6));
        Console.WriteLine("Area of Circle: " + Area(3));

    }
}