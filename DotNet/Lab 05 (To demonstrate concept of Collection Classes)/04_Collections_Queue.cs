/*4.(B) Create a Queue which takes integer values and perform following operations: 
    a. Enqueue() - Adds an item into the queue.
    b. Dequeue() - Returns an item from the beginning of the queue and removes it from the queue.
    c. Peek() - Returns an rst item from the queue without removing it.
    d. Contains() - Checks whether an item is in the queue or not
    e. Clear() - Removes all the items from the queue
    */

using System.Collections.Generic;
using System;

class Collections_Queue
{
    public static void displayStack(Queue<int> queue)
    {

        Console.WriteLine("Current items in the stack:");
        foreach (var item in queue)
        {
            Console.WriteLine($"- {item}");
        }
        Console.WriteLine();
    }
    public static void Main(string[] args)
    {
        Queue<Int32> queue = new();
        queue.Enqueue(12);
        queue.Enqueue(34);
        queue.Enqueue(56);
        queue.Enqueue(78);
        queue.Enqueue(90);

        displayStack(queue);

        Console.WriteLine($"Dequeue: {queue.Dequeue()}");
        displayStack(queue);

        Console.WriteLine($"Peek: {queue.Peek()}");
        displayStack(queue);

        Console.WriteLine($"Contains 56: {queue.Contains(56)}");
        Console.WriteLine($"Contains 100: {queue.Contains(100)}");
        Console.WriteLine();

        queue.Clear();
        displayStack(queue);

    }
}