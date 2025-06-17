/* 3.(A) Write a pogram to Create a class Bank_Account with Account_No, Email, User_Name, Account_Type and Account_Balance as 
data members. Also create a Member function GetAccountDetails() & DisplayAccountDetails().*/

class Bank_Account
{
    int Account_Number;
    string Email;
    string User_Name;
    string Account_Type;
    int Account_Balance;

    public void GetAccountDetails()
    {
        Console.WriteLine("Enter Account_Number : ");
        Account_Number = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Enter Email : ");
        Email = Console.ReadLine();
        Console.WriteLine("Enter User_Name : ");
        User_Name = Console.ReadLine();
        Console.WriteLine("Enter Account_Type : ");
        Account_Type = Console.ReadLine();
        Console.WriteLine("Enter Account_Balance : ");
        Account_Balance = Convert.ToInt32(Console.ReadLine());
    }

    public void DisplayAccountDetails()
    {
        System.Console.WriteLine($"Account_Number : {Account_Number}");
        System.Console.WriteLine($"Email : {Email}");
        System.Console.WriteLine($"User_Name : {User_Name}");
        System.Console.WriteLine($"Account_Type : {Account_Type}");
        System.Console.WriteLine($"Account_Balance : {Account_Balance}");

    }
}

class Program3
{
    public static void Main(string[] args)
    {
        Bank_Account account1 = new Bank_Account();
        account1.GetAccountDetails();
        account1.DisplayAccountDetails();
    }
}