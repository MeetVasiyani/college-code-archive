/*The abstract vegetable class has three subclasses named Potato, Brinjal and Tomato. Write a java program that 
demonstrates how to establish this class hierarchy. Declare one instance variable of type String that indicates the color of a 
vegetable. Crete and display instances of these objects. Override the toString() method of object to return a string with the 
name of vegetable and its color. */

abstract class Vegetable {
    String color;

    Vegetable(String color) {
        this.color = color;
    }

    abstract String getName();

    @Override
    public String toString() {
        return "Vegetable: " + getName() + ", Color: " + color;
    }
}

class Potato extends Vegetable {
    Potato(String color) {
        super(color);
    }

    @Override
    String getName() {
        return "Potato";
    }
}

class Brinjal extends Vegetable {
    Brinjal(String color) {
        super(color);
    }

    @Override
    String getName() {
        return "Brinjal";
    }
}

class Tomato extends Vegetable {
    Tomato(String color) {
        super(color);
    }

    @Override
    String getName() {
        return "Tomato";
    }
}

public class Q1_Inheritance_Using_Abstract_Class {
    public static void main(String[] args) {
        Potato potato = new Potato("Brown");
        Brinjal brinjal = new Brinjal("Purple");
        Tomato tomato = new Tomato("Red");

        System.out.println(potato);
        System.out.println(brinjal);
        System.out.println(tomato);
    }
}
