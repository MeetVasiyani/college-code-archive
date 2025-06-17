/*2.(A) Write a program to create a class Staff having data members as Name, Department, Designation, Experience & Salary. Accept 
this data for 5 different staffs and display only names & salary of those staff who are HOD.*/

using System;
class Staff
{
    string Name;
    string Department;
    string Designation;
    int Experience;
    int Salary;

    public string DesignationGetter()
    {
        return Designation;
    }

    public void GetStaffDetails()
    {
        Console.WriteLine("Enter Name : ");
        Name = Console.ReadLine();
        Console.WriteLine("Enter Department : ");
        Department = Console.ReadLine();
        Console.WriteLine("Enter Designation : ");
        Designation = Console.ReadLine();
        Console.WriteLine("Enter Experience : ");
        Experience = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Enter Salary : ");
        Salary = Convert.ToInt32(Console.ReadLine());
    }

    public void DisplayStaffDetails()
    {
        System.Console.WriteLine($"Name : {Name}");
        System.Console.WriteLine($"Department : {Department}");
        System.Console.WriteLine($"Designation : {Designation}");
        System.Console.WriteLine($"Experience : {Experience}");
        System.Console.WriteLine($"Salary : {Salary}");

    }

    public void DisplayHODDetails()
    {
        System.Console.WriteLine($"Name : {Name}");
        System.Console.WriteLine($"Salary : {Salary}");

    }
}
class Program2
{
    public static void Main(string[] args)
    {
        Staff[] staff = new Staff[5];

        for (int i = 0; i < 5; i++)
        {
            staff[i] = new Staff();
            staff[i].GetStaffDetails();
        }

        for (int i = 0; i < 5; i++)
        {
            if (staff[i].DesignationGetter() == "HOD")
            {
                staff[i].DisplayHODDetails();
            }
            else
            {
                staff[i].DisplayStaffDetails();
            }
        }
    }
}