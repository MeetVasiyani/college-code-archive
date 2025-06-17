/*7. (B) Write a program to find out Simple Interest using function. (I = PRN/100)*/

static double simpleIntrest(double p, double r, double t)
{
    return (p * r * t) / 100;
}

Console.WriteLine("Enter principal amount : ");
double p = Convert.ToDouble(Console.ReadLine());

Console.WriteLine("Enter rate of interest : ");
double r = Convert.ToDouble(Console.ReadLine());

Console.WriteLine("Enter time in years : ");
double t = Convert.ToDouble(Console.ReadLine());

Console.WriteLine($"Simple Intrest : {simpleIntrest(p, r, t)}");