
/* 1.(A) Write a program to create a class named Candidate with ID, Name, Age, Weight and Height as data members & also create a 
member functions like GetCandidateDetails() and DisplayCandidateDetails().*/

using System;

class Candidate
{
    int ID;
    string Name;
    int Age;
    double Weight;
    double Height;

    public void GetCandidateDetails()
    {
        Console.WriteLine("Enter ID : ");
        ID = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Enter Name : ");
        Name = Console.ReadLine();
        System.Console.WriteLine("Enter Age : ");
        Age = Convert.ToInt32(Console.ReadLine());
        System.Console.WriteLine("Enter Weight : ");
        Weight = Convert.ToDouble(Console.ReadLine());
        System.Console.WriteLine("Enter Height : ");
        Height = Convert.ToDouble(Console.ReadLine());
    }

    public void DisplayCandidateDetails()
    {
        System.Console.WriteLine($"ID : {ID}");
        System.Console.WriteLine($"Name : {Name}");
        System.Console.WriteLine($"Age : {Age}");
        System.Console.WriteLine($"Weight : {Weight}");
        System.Console.WriteLine($"Height : {Height}");

    }

}

class Program
{
    public static void Main(String[] args)
    {
        Candidate candidate1 = new Candidate();
        candidate1.GetCandidateDetails();
        candidate1.DisplayCandidateDetails();
    }
}