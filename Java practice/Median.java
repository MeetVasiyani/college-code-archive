import java.util.*;

class Main {
    public static void main(String[] args) {
        int[] A1 = {1, 12, 15, 26, 38};
        int[] A2 = {2, 13, 17, 30, 45};

        int [] A3 = new int[10];

        int i = 0,j = 0, k = 0;
        while(i < 5 && j < 5){
            if(A1[i] < A2[j]){
                A3[k++] = A1[i++];
            }else{
                A3[k++] = A2[j++];
            }
        }

        while(i < 5){
            A3[k++] = A1[i++];
        }
        while(j < 5){
            A3[k++] = A2[j++];
        }

        int total = 5+5;

        if(total % 2 != 0){
            double a = A3[Math.ceil(total/2)];
            System.out.println(a);
        }else{
            double b = (A3[(total/2)-1] + A3[(total/2)])/2.0;
            System.out.println(b);
        }
    }
}
