/* 1. (A) Write a program to print your name, address, contact number & city. */

Console.WriteLine("Enter your name: ");
string name = Console.ReadLine();

Console.WriteLine("Enter your address : ");
string address = Console.ReadLine();

Console.WriteLine("Enter your contact number : ");
string contact = Console.ReadLine();

Console.WriteLine("Enter your city : ");
string city = Console.ReadLine();

Console.WriteLine($"Name : {name}\nAddress : {address}\nContact : {contact}\nCity : {city}");
