class Main {
    public static void main(String[] args) {
        int []arr = {10,5,7,3,78};
        int i = 1;
        while(i < 5){
            int j = i-1;
            int temp = arr[i];
            while(j >= 0 && arr[j] > temp){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = temp;
            i++;
        }

        for(int k = 0; k < 5; k++){
            System.out.println(arr[k]);
        }
    }
}