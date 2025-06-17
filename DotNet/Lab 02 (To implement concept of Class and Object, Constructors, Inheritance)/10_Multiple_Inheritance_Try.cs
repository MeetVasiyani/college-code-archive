/* 10.(C) Program to implement the following multiple inheritance using interface.
 Interface: Gross
 Method- Gross_sal() Class : Salary
 Data Members - HRA, TA,DA
 Methods - Disp_sal() Class : Employee
 Data Members - Name
 Methods - basic_sal()*/

using System;

interface Gross
{
    void Gross_sal();
}

class Salary1
{
    protected double HRA, TA, DA;

    public void Disp_sal()
    {
        Console.WriteLine("HRA: " + HRA);
        Console.WriteLine("TA: " + TA);
        Console.WriteLine("DA: " + DA);
    }
}

class Employee : Salary1, Gross
{
    private string Name;
    private double basic;

    public void basic_sal(string name, double basicSalary)
    {
        Name = name;
        basic = basicSalary;
        HRA = basic * 0.1;
        TA = basic * 0.05;
        DA = basic * 0.15;
    }

    public void Gross_sal()
    {
        double gross = basic + HRA + TA + DA;
        Console.WriteLine("Employee Name: " + Name);
        Console.WriteLine("Basic Salary: " + basic);
        Disp_sal();
        Console.WriteLine("Gross Salary: " + gross);
    }
}

class Program10
{
    static void Main(string[] args)
    {
        Employee emp = new Employee();
        emp.basic_sal("Meet", 50000);
        emp.Gross_sal();
    }
}
