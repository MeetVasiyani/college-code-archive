/* 6.(A) Write a program for implementing single inheritance which creates one class Account_Details for getting account information 
and another class Interest for calculating and displaying total interest from the data inserted 
from account details.*/

using System;
class Account_Details
{
    protected int Account_Number;
    protected string Account_Holder_Name;
    protected double Account_Balance;
    protected double Interest_Rate;
    protected double Interest_Amount;


    public void GetAccountDetails()
    {
        Console.WriteLine("Enter Account_Number : ");
        Account_Number = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Enter Account_Holder_Name : ");
        Account_Holder_Name = Console.ReadLine();
        Console.WriteLine("Enter Account_Balance : ");
        Account_Balance = Convert.ToDouble(Console.ReadLine());
        Console.WriteLine("Enter Interest_Rate : ");
        Interest_Rate = Convert.ToDouble(Console.ReadLine());
    }

    public void DisplayAccountDetails()
    {
        System.Console.WriteLine($"Account_Number : {Account_Number}");
        System.Console.WriteLine($"Account_Holder_Name : {Account_Holder_Name}");
        System.Console.WriteLine($"Account_Balance : {Account_Balance}");
        System.Console.WriteLine($"Interest_Rate : {Interest_Rate}");
    }
}
class Interest : Account_Details
{
    public void CalculateInterest()
    {
        Interest_Amount = Account_Balance * Interest_Rate;
    }

    public void DisplayInterest()
    {
        Console.WriteLine("Calculating Interest...");
        CalculateInterest();
        Console.WriteLine($"Interest Amount: {Interest_Amount}");
    }
}

class Program6
{
    public static void Main(string[] args)
    {
        Interest interest = new Interest();
        interest.GetAccountDetails();
        interest.DisplayAccountDetails();
        interest.DisplayInterest();
    }
}