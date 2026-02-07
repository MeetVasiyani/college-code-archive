import java.util.*;
class Main {
    public static void main(String[] args) {
        String input = "2a3bc4dE5F2G7H";
        StringBuilder sb = new StringBuilder();
        int count = 0;

        for(int i = 0; i < input.length(); i++){
            char ch = input.charAt(i);

            if(Character.isDigit(ch)){
                count = count * 10 + ch - '0';
            }
            else{
                if(count == 0){
                    sb.append(ch);
                }
                else{
                    for(int j = 0; j < count; j++){
                        sb.append(ch);
                    }
                    count = 0;
                }
            }
        }
        System.out.println(sb.toString());
    }
}