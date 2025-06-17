/* 4. (A) Write a program to calculate the size of the area in square-feet based on Specified length and width.*/

Console.WriteLine("Enter length (in feet) : ");
double length = Convert.ToDouble(Console.ReadLine());

Console.WriteLine("Enter width (in feet) : ");
double width = Convert.ToDouble(Console.ReadLine());

double area = length * width;
Console.WriteLine($"Area in square feet : {area}");