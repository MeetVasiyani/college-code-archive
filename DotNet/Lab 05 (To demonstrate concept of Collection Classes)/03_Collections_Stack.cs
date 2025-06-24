/* 3.(B) Create a Stack which takes integer values and perform following operations:
    a. Push() - To Add new item in stack
    b. Pop() - To Remove item from the stack
    c. Peek() – To Return the top item from the stack.
    d. Contains() - To Checks whether an item exists in the stack or not.
    e. Clear() - To clear items from stack
    */

using System;
using System.Collections.Generic;


class Collections_Stack
{
    public static void displayStack(Stack<int> stack)
    {
        
        Console.WriteLine("Current items in the stack:");
        foreach (var item in stack)
        {
            Console.WriteLine($"- {item}");
        }
        Console.WriteLine();
    }
    public static void Main(string[] args)
    {
        Stack<Int32> stack = new Stack<int>();

        stack.Push(12);
        stack.Push(34);
        stack.Push(56);
        stack.Push(78);

        displayStack(stack);

        int temp = stack.Pop();
        System.Console.WriteLine($"Popped Element : {temp}");

        displayStack(stack);

        System.Console.WriteLine($"Peek Element : {stack.Peek()}");

        System.Console.WriteLine($"Does stack contain 34 : {stack.Contains(34)}");
        System.Console.WriteLine($"Does stack contain 100 : {stack.Contains(100)}");

        stack.Clear();

        displayStack(stack);
    }

}