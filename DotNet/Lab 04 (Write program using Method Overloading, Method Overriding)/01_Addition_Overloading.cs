/* 1.(A) Write a program using method overloading by changing datatype of arguments to perform addition of two integer numbers 
and two float numbers.*/

using System;

class Addition_Methods
{
    public int Addition(int a, int b)
    {
        return a + b;
    }

    public float Addition(float a, float b)
    {
        return a + b;
    }
}

class program
{
    public static void Main(string[] args)
    {
        Addition_Methods obj = new Addition_Methods();
        Console.WriteLine("Addition of two integer numbers: "+obj.Addition(10, 20));
        Console.WriteLine("Addition of two float numbers: "+obj.Addition(10.5f, 20.75f));
    
    }
}