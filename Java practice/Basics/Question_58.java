import java.util.*;
class Main{
    public static List<List<String>> groupAnagrams(List<String> input){
        HashMap<String,List<String>> map = new HashMap<>();

        for(String str : input){
            char [] ch = str.toCharArray();
            Arrays.sort(ch);
            String key = new String(ch);
            if(map.containsKey(key)){
                map.get(key).add(str);
            }
            else{
                List<String> temp = new ArrayList<>();
                temp.add(str);
                map.put(key,temp);
            }
        }
        return new ArrayList<>(map.values());
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter size of list : ");
        int n = sc.nextInt();
        sc.nextLine();

        List<String> list = new ArrayList<>();

        for(int i = 0; i < n; i++){
            System.out.println("Enter the word : ");
            list.add(sc.nextLine());
        }
        
        List<List<String>> result = groupAnagrams(list);

        for(List<String> group : result){
            System.out.println(group);
        }
        sc.close();
    }
}