/*Write a program to create two threads, one thread will print odd numbers and second thread will print even numbers 
between 1 to 20 numbers.*/
// Class to print odd numbers
class OddNumberPrinter implements Runnable {
    @Override
    public void run() {
        for (int i = 1; i <= 20; i++) {
            if (i % 2 != 0) {
                System.out.println("Odd Thread: " + i);
                try {
                    Thread.sleep(200); // Sleep for 200 milliseconds
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}

// Class to print even numbers
class EvenNumberPrinter implements Runnable {
    @Override
    public void run() {
        for (int i = 1; i <= 20; i++) {
            if (i % 2 == 0) {
                System.out.println("Even Thread: " + i);
                try {
                    Thread.sleep(200); // Sleep for 200 milliseconds
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}

// Main class to demonstrate the threads
public class Q2_MultiThreading_OddNumber_EvenNumber {
    public static void main(String[] args) {
        // Creating instances of runnable tasks
        OddNumberPrinter oddPrinter = new OddNumberPrinter();
        EvenNumberPrinter evenPrinter = new EvenNumberPrinter();

        // Creating threads for each task
        Thread oddThread = new Thread(oddPrinter);
        Thread evenThread = new Thread(evenPrinter);

        // Starting the threads
        oddThread.start();
        evenThread.start();
    }
}