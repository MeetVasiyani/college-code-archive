/*4.(A) Write a program to create interface Calculate. In this interface we have two member functions Addition() and Subtraction(). 
Implements this interface in another class named Result. */

using System;
public interface ICalculate
{
    public abstract int Addition(int a,int b);
    public abstract int Substraction(int a,int b);
}

class Result : ICalculate
{
    public int Addition(int a, int b)
    {
        return a + b;
    }

    public int Substraction(int a, int b)
    {
        return a - b;
    }
}

class Interface
{
    public static void Main(string[] args)
    {
        Result result = new Result();
        System.Console.WriteLine("Enter First Number : ");
        int a = Convert.ToInt32(Console.ReadLine());
        System.Console.WriteLine("Enter Second Number : ");
        int b = Convert.ToInt32(Console.ReadLine());

        System.Console.WriteLine($"Sum of given numbers : {result.Addition(a, b)}");
        System.Console.WriteLine($"Difference of given numbers : {result.Substraction(a,b)}");
    }
}