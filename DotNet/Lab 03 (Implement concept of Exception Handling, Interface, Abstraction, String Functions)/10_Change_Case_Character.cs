/*10.(C) Write a program to change the case of entered character.*/

using System;
class Change_Case_Character
{
    public static void Main(string[] args)
    {
        System.Console.WriteLine("Enter a character : ");
        char ch = Console.ReadLine()[0];

        if (char.IsUpper(ch))
        {
            System.Console.WriteLine("To lower case : "+char.ToLower(ch));
        }
        else
        {
            System.Console.WriteLine("To upper case : "+char.ToUpper(ch));
        }
    }
}