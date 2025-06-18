/* 6.(C) Create a BankAccount class having constructor accepting initialBalance and accountHolderName. Also create Deposite() and 
withdraw() overloaded methods by which user can deposit/withdraw amount using different types of parameters (ex. cash, check).*/
using System;

class Bank_Account_Method_Overloading
{
    int initialBalance;
    string accountHolderName;
    public Bank_Account_Method_Overloading(int initialBalance, string accountHolderName)
    {
        this.accountHolderName = accountHolderName;
        this.initialBalance = initialBalance;
    }

    public void Deposit(double amount)
    {
        initialBalance += (int)amount;
        Console.WriteLine($"Deposited: {amount:C}, New Balance: {initialBalance:C}");
    }

    public void Deposit(double amount, string checkNumber)
    {
        initialBalance += (int)amount;
        Console.WriteLine($"Deposited via check {checkNumber}: {amount:C}, New Balance: {initialBalance:C}");
    }

    public void Withdraw(double amount)
    {
        if (amount > initialBalance)
        {
            Console.WriteLine($"Insufficient funds for withdrawal of {amount:C}. Current balance: {initialBalance:C}");
        }
        else
        {
            initialBalance -= (int)amount;
            Console.WriteLine($"Withdrew: {amount:C}, New Balance: {initialBalance:C}");
        }
    }
}

public class Program
{
    public static void Main(string[] args)
    {
        Bank_Account_Method_Overloading account = new Bank_Account_Method_Overloading(1000, "John Doe");
        
        Console.WriteLine($"Account Holder: {account.accountHolderName}");
        Console.WriteLine($"Initial Balance: {account.initialBalance:C}");
        
        account.Deposit(200);
        account.Withdraw(150);
        account.Deposit(300, "CHK12345");
        account.Withdraw(500);
        account.Withdraw(1000);     
    }
}
