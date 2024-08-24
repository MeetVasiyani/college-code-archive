/*The Transport interface declares a deliver () method. The abstract class Animal is the super class of the Tiger, Camel, Deer 
and Donkey classes. The Transport interface is implemented by the Camel and Donkey classes. Write a test program that 
initialize an array of four Animal objects. If the object implements the Transport interface, the deliver () method is invoked. */
import java.util.Scanner;
interface Transport {
    void deliver();
}

abstract class Animal {
    public abstract void makeSound();
}

class Tiger extends Animal {
    @Override
    public void makeSound() {
        System.out.println("Roar!");
    }
}

class Camel extends Animal implements Transport {
    @Override
    public void makeSound() {
        System.out.println("Hump!");
    }

    @Override
    public void deliver() {
        System.out.println("The camel delivers goods across the desert.");
    }
}

class Deer extends Animal {
    @Override
    public void makeSound() {
        System.out.println("Bambi!");
    }
}

class Donkey extends Animal implements Transport {
    @Override
    public void makeSound() {
        System.out.println("Hee-haw");
    }

    @Override
    public void deliver() {
        System.out.println("The donkey carries goods in the mountains.");
    }
}


public class Q3_Instance_Of_Operator_Demo {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Animal[] animals = new Animal[4];

        // Initialize the array with Animal objects
        for (int i = 0; i < animals.length; i++) {
            System.out.print("Enter the type of animal (Tiger, Camel, Deer, Donkey): ");
            String animalType = scanner.nextLine();

            switch (animalType) {
                case "Tiger":
                    animals[i] = new Tiger();
                    break;
                case "Camel":
                    animals[i] = new Camel();
                    break;
                case "Deer":
                    animals[i] = new Deer();
                    break;
                case "Donkey":
                    animals[i] = new Donkey();
                    break;
                default:
                    System.out.println("Invalid animal type. Please enter Tiger, Camel, Deer, or Donkey.");
                    i--; // Decrement i to re-enter the loop for this index
            }
        }

        // Invoke the deliver() method for objects that implement the Transport interface
        for (Animal animal : animals) {
            if (animal instanceof Transport) {
                ((Transport) animal).deliver();
            }
        }

        scanner.close();
    }
}

