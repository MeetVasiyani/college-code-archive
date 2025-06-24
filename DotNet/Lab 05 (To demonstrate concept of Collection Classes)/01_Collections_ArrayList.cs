/*
1.(A) Create an ArrayList for StudentName and perform following operations:
    a. Add() - To Add new student in list
    b. Remove() - To Remove Student with speci ed index
    c. RemoveRange() - To Remove student with speci ed range.
    d. Clear() - To clear all the student from the list
*/
using System.Collections;

class Collections_ArrayList
{
    
    public static void displayList(ArrayList arrayList)
    {
        for (int i = 0; i < arrayList.Count; i++)
        {
            System.Console.Write(arrayList[i] + ", ");
        }
        System.Console.WriteLine("\n");
    }

    public static void Main(string[] args)
    {
        ArrayList arrayList = new ArrayList();
        arrayList.Add(20);
        arrayList.Add("Hello");
        arrayList.Add(3.14);
        arrayList.Add("Pandas");
        arrayList.Add(438);
        arrayList.Add("C#");
        arrayList.Add("ArrayList");
        arrayList.Add("Collections");

        displayList(arrayList);

        arrayList.Remove("Hello");
        arrayList.Remove(20);

        displayList(arrayList);

        arrayList.RemoveRange(3, 2);

        displayList(arrayList);

        arrayList.Clear();

        displayList(arrayList);
    }
}