/* 7.(B) Write a program to create interface named Shape. In this interface, we have three methods Circle(), Triangle() and Square() 
which calculates area of Circle, Triangle and Square respectively. Implement Shape interface.*/

using System;

interface Shape
{
    public abstract int Circle(int radius);
    public abstract int Triangle(int h, int b);
    public abstract int Square(int side);
}

class Shape_Interface : Shape
{
    public int Circle(int radius)
    {
        return (int)(Math.PI * radius * radius);
    }

    public int Square(int side)
    {
        return side * side;
    }

    public int Triangle(int h, int b)
    {
        return (h * b) / 2;

    }

    public static void Main(string[] args)
    {
        Shape_Interface s = new Shape_Interface();
        System.Console.WriteLine("Enter Radius of Circle : ");
        int r = Convert.ToInt32(Console.ReadLine());
        System.Console.WriteLine("Area of Circle is : " + s.Circle(r));
    }
}