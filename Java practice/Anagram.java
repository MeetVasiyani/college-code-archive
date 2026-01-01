import java.util.*;

class Main {
    public static void main(String[] args) {
        String s1 = "geeks";
        String s2 = "kseeg";

        if (s1.length() != s2.length()) {
            System.out.println("Not anagram");
            return;
        }

        HashMap<Character, Integer> map = new HashMap<>();

        for (char ch : s1.toCharArray()) {
            map.put(ch, map.getOrDefault(ch, 0) + 1);
        }

        for (char ch : s2.toCharArray()) {
            if (!map.containsKey(ch)) {
                System.out.println("Not anagram");
                return;
            }
            map.put(ch, map.get(ch) - 1);
            if (map.get(ch) == 0) {
                map.remove(ch);
            }
        }

        System.out.println(map.isEmpty() ? "Anagram" : "Not anagram");
    }
}
