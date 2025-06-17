/* 3.(A) Write a program to create an abstract class Sum having abstract methods SumOfTwo(int a, int b) and SumOfThree(int a, int 
b,int c). Create another class Calculate which extends the abstract class and implements the abstract methods.*/

using System;

public abstract class Sum
{
    public abstract int SumOfTwo(int a, int b);
    public abstract int SumOfThree(int a, int b, int c);
}

public class Calculate : Sum
{
    public override int SumOfThree(int a, int b, int c)
    {
        return a+b+c;
    }

    public override int SumOfTwo(int a, int b)
    {
        return a+b;
    }
}

class Abstract_Class
{
    public static void Main(string[] args)
    {
        Calculate calculate = new Calculate();
        System.Console.WriteLine("Enter First Number : ");
        int a = Convert.ToInt32(Console.ReadLine());
        System.Console.WriteLine("Enter Second Number : ");
        int b = Convert.ToInt32(Console.ReadLine());

        System.Console.WriteLine($"Sum of two numbers : {calculate.SumOfTwo(a,b)}");
    }
}