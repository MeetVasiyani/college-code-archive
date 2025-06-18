/*2.(A) Write a program using method overloading by changing number of arguments to calculate area of square and rectangle.*/

using System;

class AreaCalculator
{
    public double CalculateArea(double side)
    {
        return side * side;
    }

    public double CalculateArea(double length, double width)
    {
        return length * width;
    }

    static void Main(string[] args)
    {
        AreaCalculator calculator = new AreaCalculator();

        double squareSide = 5.0;
        double squareArea = calculator.CalculateArea(squareSide);
        Console.WriteLine($"Area of the square with side {squareSide}: {squareArea}");

        double rectangleLength = 6.0;
        double rectangleWidth = 4.0;
        double rectangleArea = calculator.CalculateArea(rectangleLength, rectangleWidth);
        Console.WriteLine($"Area of the rectangle with length {rectangleLength} and width {rectangleWidth}: {rectangleArea}");
    }
}
