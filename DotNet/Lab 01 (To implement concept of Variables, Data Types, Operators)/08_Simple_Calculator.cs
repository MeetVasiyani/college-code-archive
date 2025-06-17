/*8. (B) Write a program to create a Simple Calculator for two numbers (Addition, Multiplication, Subtraction, Division) [Also using 
if…else & Switch Case]*/

Console.WriteLine("Enter first number : ");
double num1 = Convert.ToDouble(Console.ReadLine());

Console.WriteLine("Enter second number : ");
double num2 = Convert.ToDouble(Console.ReadLine());

Console.WriteLine("Enter 1 for Addition\nEnter 2 for Subtraction\nEnter 3 for Multiplication\nEnter 4 for Division");
int temp = Convert.ToInt32(Console.ReadLine());

switch (temp)
{
    case 1:
        Console.WriteLine($"Addition : {num1 + num2}");
        break;
    case 2:
        Console.WriteLine($"Subtraction : {num1 - num2}");
        break;
    case 3:
        Console.WriteLine($"Multiplication : {num1 * num2}");
        break;
    case 4:
        if (num2 != 0)
        {
            Console.WriteLine($"Division : {num1 / num2}");
        }
        else
        {
            Console.WriteLine("Cannot divide by zero");
        }
        break;
    default:
        Console.WriteLine("Invalid input");
        break;
}