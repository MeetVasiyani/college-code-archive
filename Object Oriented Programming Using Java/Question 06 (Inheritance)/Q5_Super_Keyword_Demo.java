/* Demonstrate the use of Super Keyword. */

class Animal {
    String name;
    int age;

    Animal(String name, int age) {
        this.name = name;
        this.age = age;
    }

    void eat() {
        System.out.println("Animal is eating.");
    }
}

class Dog extends Animal {
    String breed;

    Dog(String name, int age, String breed) {
        super(name, age);
        this.breed = breed;
    }

    @Override
    void eat() {
        System.out.println("Dog is eating.");
    }

    void bark() {
        System.out.println("Dog is barking.");
    }
}

public class Q5_Super_Keyword_Demo {
    public static void main(String[] args) {
        Dog dog = new Dog("Buddy", 5, "Golden Retriever");

        System.out.println("Dog name: " + dog.name);
        System.out.println("Dog age: " + dog.age);
        System.out.println("Dog breed: " + dog.breed);

        dog.eat();
        dog.bark();
    }
}