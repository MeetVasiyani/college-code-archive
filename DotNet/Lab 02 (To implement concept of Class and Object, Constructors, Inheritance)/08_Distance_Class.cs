/* 8.(B) Write a program to Define a class Distance have data members dist1, dist2, dist3. Initialize the two data members using 
constructor and store their addition in third data member using function and display addition.*/

using System;

class Distance
{
    int dist1, dist2, dist3;

    public Distance(int dist1, int dist2)
    {
        this.dist1 = dist1;
        this.dist2 = dist2;
        this.dist3 = dist1 + dist2;
    }

    public void display()
    {
        Console.WriteLine("Distance 1: " + dist1);
        Console.WriteLine("Distance 2: " + dist2);
        Console.WriteLine("Total Distance: " + dist3);
    }

    public static void Main(string[] args)
    {
        Distance d = new Distance(10, 20);
        d.display();
    }
}