/* Write a program that illustrates interface inheritance. Interface A is extended by A1 and A2. Interface A12 inherits from both 
P1 and P2.Each interface declares one constant and one method. Class B implements A12.Instantiate B and invoke each of 
its methods. Each method displays one of the constants */
interface A {
    int CONSTANT_A = 10;

    void methodA();
}

interface A1 extends A {
    int CONSTANT_A1 = 20;

    void methodA1();
}

interface A2 extends A {
    int CONSTANT_A2 = 30;

    void methodA2();
}

interface A12 extends A1, A2 {
    int CONSTANT_A12 = 40;

    void methodA12();
}

class B implements A12 {
    @Override
    public void methodA() {
        System.out.println("Constant A: " + A.CONSTANT_A);
    }

    @Override
    public void methodA1() {
        System.out.println("Constant A1: " + A1.CONSTANT_A1);
    }

    @Override
    public void methodA2() {
        System.out.println("Constant A2: " + A2.CONSTANT_A2);
    }

    @Override
    public void methodA12() {
        System.out.println("Constant A12: " + A12.CONSTANT_A12);
    }
}

public class Q2_Inheritance_Using_Interface {
    public static void main(String[] args) {
        B b = new B();
        b.methodA();
        b.methodA1();
        b.methodA2();
        b.methodA12();
    }
}
