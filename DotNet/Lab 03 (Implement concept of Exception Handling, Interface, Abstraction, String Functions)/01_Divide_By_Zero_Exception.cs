/* 1.(A) Write a program to Create a divide by zero exception and handle it.*/


class Divide_By_Zero_Exception
{
    public static void Main(string[] args) {
        try
        {
            int b = 0;
            float a = 15 / b;
            System.Console.WriteLine("Division Possible !!!");
        }
        catch (System.Exception e)
        {
            System.Console.WriteLine(e.Message);
        }
    }
}