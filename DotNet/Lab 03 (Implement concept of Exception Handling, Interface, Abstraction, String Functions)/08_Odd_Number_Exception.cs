/* 8.(B) Write a program to accept a number from the user and throw an exception if the number is not an even number.*/

using System;

class Odd_Number_Exception
{

    public static void Main(string[] args)
    { 
        try
        {
            Console.WriteLine("Enter a number: ");
            int num = int.Parse(Console.ReadLine());
            if (num % 2 != 0)
            {
                throw new Exception("Number is not even.");
            }
            else
            {
                Console.WriteLine("Number is even.");
            }
            
        }
        catch (System.Exception e)
        {
            System.Console.WriteLine(e.Message);
        }
    }
    
}