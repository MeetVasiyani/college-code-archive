/* 9.(C) Create a class Furniture with material ,price as data members. Create another class Table with Height , surface_area as data 
members. Write a program to implement single inheritance.*/

using System;


class Furniture
{
    protected string material;
    protected int price;

    public Furniture(string material, int price)
    {
        this.material = material;
        this.price = price;
    }

}

class Table : Furniture
{
    int height;
    int surface_area;

    public Table(string material, int price, int height, int surface_area)
        : base(material, price)
    {
        this.height = height;
        this.surface_area = surface_area;

    }

    public void display()
    {
        Console.WriteLine("Material: " + material);
        Console.WriteLine("Price: " + price);
        Console.WriteLine("Height: " + height);
        Console.WriteLine("Surface Area: " + surface_area);
    }
}

class Program9
{
    public static void Main(string[] args)
    {
        Table t = new Table("Wood", 5000, 100, 500);
        t.display();
    }

}