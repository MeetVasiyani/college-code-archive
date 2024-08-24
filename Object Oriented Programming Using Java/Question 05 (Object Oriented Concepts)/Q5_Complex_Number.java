/*Define class for Complex number with real and imaginary as data members. Create its contructor, overload the constructors. 
Also define addition method to add two complex objects. */
import java.util.Scanner;

public class Q5_Complex_Number {
    double real;
    double imaginary;

    public Q5_Complex_Number() {
        this.real = 0;
        this.imaginary = 0;
    }

    public Q5_Complex_Number(double real, double imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    public Q5_Complex_Number add(Q5_Complex_Number other) {
        double newReal = this.real + other.real;
        double newImaginary = this.imaginary + other.imaginary;
        return new Q5_Complex_Number(newReal, newImaginary);
    }

    @Override
    public String toString() {
        return String.format("%f + %fi", real, imaginary);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the real part of the first complex number: ");
        double real1 = scanner.nextDouble();
        System.out.print("Enter the imaginary part of the first complex number: ");
        double imaginary1 = scanner.nextDouble();

        System.out.print("Enter the real part of the second complex number: ");
        double real2 = scanner.nextDouble();
        System.out.print("Enter the imaginary part of the second complex number: ");
        double imaginary2 = scanner.nextDouble();

        Q5_Complex_Number complex1 = new Q5_Complex_Number(real1, imaginary1);
        Q5_Complex_Number complex2 = new Q5_Complex_Number(real2, imaginary2);

        Q5_Complex_Number sum = complex1.add(complex2);

        System.out.println("The sum of the two complex numbers is: " + sum);

        scanner.close();
    }
}
