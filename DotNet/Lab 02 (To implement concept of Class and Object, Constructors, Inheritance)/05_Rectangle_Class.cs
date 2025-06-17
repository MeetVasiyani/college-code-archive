/* 5.(A) Write a program to calculate area of a Rectangle using constructor.*/

using System.Drawing;

class Rectangle
{
    int length;
    int breadth;
    int area;

    public Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
        area = length * breadth;
    }

    public void Display()
    {
        System.Console.WriteLine("Length: " + length);
        System.Console.WriteLine("Breadth: " + breadth);
        System.Console.WriteLine("Area: " + area);
    }
}

class Program5
{
    public static void Main(string[] args)
    {
        Rectangle rect = new Rectangle(5, 10);
        rect.Display();
    }
}