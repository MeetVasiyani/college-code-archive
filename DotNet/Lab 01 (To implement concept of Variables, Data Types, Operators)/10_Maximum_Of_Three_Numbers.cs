/* 10. (C)Write a program to nd maximum numbers from given 3 numbers using ternary operator*/

Console.WriteLine("Enter first number : ");
int num1 = Convert.ToInt32(Console.ReadLine());

Console.WriteLine("Enter second number : ");
int num2 = Convert.ToInt32(Console.ReadLine());

Console.WriteLine("Enter third number : ");
int num3 = Convert.ToInt32(Console.ReadLine());

int max = (num1 > num2) ? ((num1 > num3) ? num1 : num3) : ((num2 > num3) ? num2 : num3);

Console.WriteLine($"Maximum number is : {max}");
