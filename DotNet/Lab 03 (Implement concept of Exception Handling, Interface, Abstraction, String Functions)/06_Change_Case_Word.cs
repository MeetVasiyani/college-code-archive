/* 6.(B) Write a program to Replace lower case characters to upper case and Vice-versa.*/
using System;
class Change_Case
{
    public static void Main(string[] args)
    {
        System.Console.WriteLine("Enter String : ");
        string str = Console.ReadLine();
        string result = "";

        for (int i = 0; i < str.Length; i++)
        {
            if (char.IsLower(str[i]))
            {
                result += char.ToUpper(str[i]);
            }
            else if (char.IsUpper(str[i]))
            {
                result += char.ToLower(str[i]);
            }
            else
            {
                result += str[i];
            }
        }
        System.Console.WriteLine($"Result String : {result}");
    }
}
