/*7.(B) Write a program to Define a class Salary which will contain member variable Basic, TA, DA, HRA. Write a program using 
Constructor with default values for DA and HRA and calculate the salary of employee.*/

class Salary
{
    double Basic;
    double TA;
    double DA;
    double HRA;

    public Salary(double Basic, double TA, double DA = 15000, double HRA = 3000)
    {
        this.Basic = Basic;
        this.TA = TA;
        this.DA = DA;
        this.HRA = HRA;
    }
    public double CalculateSalary()
    {
        return Basic + TA + DA + HRA;
    }

    public void DisplaySalary()
    {
        System.Console.WriteLine("Basic: " + Basic);
        System.Console.WriteLine("TA: " + TA);
        System.Console.WriteLine("DA: " + DA);
        System.Console.WriteLine("HRA: " + HRA);
        System.Console.WriteLine("Total Salary: " + CalculateSalary());
    }

}

class Program7
{
    public static void Main(string[] args)
    { 
        Salary salary1 = new Salary(50000, 10000);
        salary1.DisplaySalary();        
    }
}
