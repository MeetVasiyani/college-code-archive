/*9.(C) Write a program to find the longest word in a string.*/

using System;

class Longest_Word_In_String
{
    public static void Main(string[] args)
    {   
        System.Console.WriteLine("Enter a string: ");
        string str = Console.ReadLine();

        char[] seperators = [' '];

        string[] words = str.Split(seperators, StringSplitOptions.RemoveEmptyEntries);

        string longestWord = words[0];
        int maxLength = longestWord.Length;

        foreach (string word in words)
        {
            if (word.Length > maxLength)
            {
                longestWord = word;
                maxLength = word.Length;
            }
        }
        Console.WriteLine("The longest word in the string is: " + longestWord);
    }
}