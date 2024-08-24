/*Write a program to accept a line and check how many consonants and vowels are there in line. */
public class Q2_Number_Of_Constants_And_Vowels {
    public static void main(String[] args) {
        String s = args[0];
        int vow = 0, cons = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (Character.isLetter(c)) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                    c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                    vow++;
                } else {
                    cons++;
                }
            }
        }
        System.out.println("Number of Vowels: " + vow);
        System.out.println("Number of Consonants: " + cons);
    }
}

