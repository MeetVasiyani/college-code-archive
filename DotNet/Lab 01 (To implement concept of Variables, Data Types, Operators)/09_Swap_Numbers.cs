/* 9. (C) Write a program to Swapping without using third variable.*/

Console.WriteLine("Enter first number : ");
int num1 = Convert.ToInt32(Console.ReadLine());

Console.WriteLine("Enter second number : ");
int num2 = Convert.ToInt32(Console.ReadLine());

Console.WriteLine($"Before Swapping : num1 = {num1}, num2 = {num2}");

num1 = num1 + num2;
num2 = num1 - num2;
num1 = num1 - num2;

Console.WriteLine($"After Swapping : num1 = {num1}, num2 = {num2}");