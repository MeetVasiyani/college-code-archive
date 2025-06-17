/*2.(A) Write a program that reads 5 numbers from user. Demonstrate concept of IndexOutOfRange Exception.*/

using System;
class Index_Out_Of_Range_Exception
{
    public static void Main(string[] args)
    {
        int[] arr = new int[5];

        for (int i = 0; i < 5; i++)
        {
            System.Console.WriteLine($"Enter number for index {i} : ");
            arr[i] = Convert.ToInt32(Console.ReadLine());
        }

        try
        {
            for (int i = 0; i < 6; i++)
            {
                System.Console.WriteLine($"Number at index {i} : {arr[i]}");
            }
        }
        catch (System.Exception e)
        {
            System.Console.WriteLine(e.Message);
        }

    }
}