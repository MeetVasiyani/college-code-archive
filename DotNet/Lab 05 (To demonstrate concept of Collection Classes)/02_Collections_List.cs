/*
2.(A) Create a List for StudentName and perform following operations:
    a. Add() - To Add new student in list
    b. Remove() - To Remove Student with specified index
    c. RemoveRange() - To Remove student with speci ed range.
    d. Clear() - To clear all the student from the list.
*/

using System;
using System.Collections.Generic;

class Collections_List
{
    public static void displayList(List<string> list)
    {
        if (list.Count == 0)
        {
            Console.WriteLine("The list is empty.");
        }
        else
        {
            Console.WriteLine("Current students in the list:");
            foreach (string item in list)
            {
                Console.WriteLine($"- {item}");
            }
        }
        Console.WriteLine();
    }

    public static void Main(string[] args)
    {

        List<string> studentNames = new List<string>();
        Console.WriteLine("--- Initial empty list ---");
        displayList(studentNames);

        Console.WriteLine("--- a. Adding students using Add() ---");
        studentNames.Add("Alice");
        studentNames.Add("Bob");
        studentNames.Add("Charlie");
        studentNames.Add("David");
        studentNames.Add("Eve");
        displayList(studentNames);

        Console.WriteLine("--- b. Removing student at index 2 ('Charlie') using RemoveAt() ---");
        studentNames.RemoveAt(2);
        displayList(studentNames);

        Console.WriteLine("--- c. Removing 2 students starting from index 1 ('Bob', 'David') using RemoveRange() ---");
        studentNames.RemoveRange(1, 2);
        displayList(studentNames);

        Console.WriteLine("--- d. Clearing all students using Clear() ---");
        studentNames.Clear();
        displayList(studentNames);
    }
}