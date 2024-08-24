/* WAP that counts the number of objects created using static.*/

class CountObjects {
    static int count = 0;

    CountObjects() {
        count++;
    }

    static void showCount() {
        System.out.println("Number of objects created: " + count);
    }
}

public class Q6_Count_Static_Methods {
    @SuppressWarnings("unused")
    public static void main(String[] args) {
        CountObjects obj1 = new CountObjects();
        CountObjects obj2 = new CountObjects();
        CountObjects obj3 = new CountObjects();

        CountObjects.showCount();
    }
}
