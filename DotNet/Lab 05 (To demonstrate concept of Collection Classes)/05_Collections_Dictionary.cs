/* 5.(C) Create a Dictionary collection class object and preform following operations:
    a. Add: Adds a key-value pair.
    b. Remove: Removes a key-value pair by key.
    c. ContainsKey: Checks if a key exists in the hashtable.
    d. ContainsValue: Checks if a value exists in the hashtable.
    e. Clear: Removes all key-value pairs.*/

using System;
using System.Collections.Generic;

class Collections_Dictionary
{
    public static void displayDictionary(Dictionary<string, List<string>> things)
    {
        Console.WriteLine("Dictionary contents:");
        foreach (var item in things)
        {
            Console.WriteLine($"{item.Key}: {string.Join(", ", item.Value)}");
        }
        Console.WriteLine();
    }

    public static void Main(string[] args)
    {
        Dictionary<string, List<string>> things = new();

        things.Add("Animals", ["Bee", "Pandas", "Fish", "Tree"]);
        things.Add("Colors", ["Red", "Blue", "Green"]);
        things.Add("Numbers", ["One", "Two", "Three"]);
        things.Add("Shapes", ["Circle", "Square", "Triangle"]);

        // a. Add
        things.Add("Fruits", ["Apple", "Banana", "Cherry"]);

        // b. Remove
        things.Remove("Shapes");
        displayDictionary(things);

        // c. ContainsKey
        Console.WriteLine($"Contains key 'Colors': {things.ContainsKey("Colors")}");

        // d. ContainsValue
        Console.WriteLine($"Contains value '[\"Apple\", \"Banana\", \"Cherry\"]': {things.ContainsValue(["Apple", "Banana", "Cherry"])}");

        // e. Clear
        things.Clear();
        displayDictionary(things);
        Console.WriteLine($"Count after clearing: {things.Count}");
    }
}