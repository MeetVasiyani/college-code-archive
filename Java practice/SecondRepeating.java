String str = "geeksforgeeks";
HashSet<Character> set = new HashSet<>();

for (Character ch : str.toCharArray()) {
    if (!set.contains(ch)) {
        set.add(ch);
    } else {
        System.out.println(ch);
        break;
    }
}
