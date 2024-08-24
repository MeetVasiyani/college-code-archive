/* Demonstrate the use of Collection Framework in Java */
import java.util.*;

public class Q1_Collection_Framework_Example {

    public static void main(String[] args) {
        // List Example: ArrayList
        List<String> arrayList = new ArrayList<>();
        arrayList.add("Alice");
        arrayList.add("Bob");
        arrayList.add("Charlie");
        arrayList.add("Alice");  // Duplicate
        System.out.println("ArrayList:");
        for (String name : arrayList) {
            System.out.println(name);
        }

        // Set Example: HashSet
        Set<String> hashSet = new HashSet<>();
        hashSet.add("Alice");
        hashSet.add("Bob");
        hashSet.add("Charlie");
        hashSet.add("Alice");  // Duplicate, won't be added
        System.out.println("\nHashSet:");
        for (String name : hashSet) {
            System.out.println(name);
        }

        // Map Example: HashMap
        Map<Integer, String> hashMap = new HashMap<>();
        hashMap.put(1, "Alice");
        hashMap.put(2, "Bob");
        hashMap.put(3, "Charlie");
        hashMap.put(1, "Dave");  // Key 1 will be updated to "Dave"
        System.out.println("\nHashMap:");
        for (Map.Entry<Integer, String> entry : hashMap.entrySet()) {
            System.out.println("Key: " + entry.getKey() + ", Value: " + entry.getValue());
        }

        // Queue Example: PriorityQueue
        Queue<String> priorityQueue = new PriorityQueue<>();
        priorityQueue.add("Charlie");
        priorityQueue.add("Alice");
        priorityQueue.add("Bob");
        System.out.println("\nPriorityQueue:");
        while (!priorityQueue.isEmpty()) {
            System.out.println(priorityQueue.poll());
        }

        // Deque Example: ArrayDeque
        Deque<String> arrayDeque = new ArrayDeque<>();
        arrayDeque.addFirst("Alice");
        arrayDeque.addLast("Bob");
        arrayDeque.addFirst("Charlie");
        System.out.println("\nArrayDeque:");
        for (String name : arrayDeque) {
            System.out.println(name);
        }
    }
}
