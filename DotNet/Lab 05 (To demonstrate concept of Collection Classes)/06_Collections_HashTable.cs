/*6.(C) Create a Hashtable collection class object and preform following operations:
    a. Add: Adds a key-value pair.
    b. Remove: Removes a key-value pair by key.
    c. ContainsKey: Checks if a key exists in the hashtable.
    d. ContainsValue: Checks if a value exists in the hashtable.
    e. Clear: Removes all key-value pairs. 
    */

using System.Collections;
using System;

class Collections_HashTable
{
    public static void Main(string[] args)
    {
        Hashtable things = new Hashtable();

        things.Add("Animals", "Bee, Pandas, Fish, Tree");
        things.Add("Colors", "Red, Blue, Green");
        things.Add("Numbers", "One, Two, Three");
        things.Add("Shapes", "Circle, Square, Triangle");

        things.Remove("Shapes");

        Console.WriteLine("Hashtable contents:");
        foreach (DictionaryEntry item in things)
        {
            Console.WriteLine($"{item.Key}: {item.Value}");
        }
        Console.WriteLine();

        Console.WriteLine($"Contains key 'Colors': {things.ContainsKey("Colors")}");

        Console.WriteLine($"Contains value 'Red, Blue, Green': {things.ContainsValue("Red, Blue, Green")}");

        things.Clear();
        Console.WriteLine($"Count after clearing: {things.Count}");
    }
}