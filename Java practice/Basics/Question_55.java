import java.util.*;
class Main{
    public static String nextPermutation(StringBuilder sb){
        int n = sb.length();
        int pivot = -1;
        for(int i = n-2; i >= 0; i--){
            if(sb.charAt(i) < sb.charAt(i+1)){
                pivot = i;
                break;
            }
        }
        if(pivot == -1){
            return sb.reverse().toString();
        }
        for(int i = n-1; i > pivot; i--){
            if(sb.charAt(i) > sb.charAt(pivot)){
                char temp = sb.charAt(i);
                sb.setCharAt(i,sb.charAt(pivot));
                sb.setCharAt(pivot,temp);
                break;
            }
        }

        int left = pivot+1,right = n-1;
        while(left <= right){
            char temp = sb.charAt(left);
            sb.setCharAt(left,sb.charAt(right));
            sb.setCharAt(right,temp);
            left++;
            right--;
        }

        return sb.toString();

    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String input = sc.nextLine();

        String result = nextPermutation(new StringBuilder(input));

        System.out.println("Next Permuation : " + result);

        sc.close();
    }
}