class Main {
    public static void main(String[] args) {
        int []arr = {5 ,1 ,9, 7, 1, 5, 3 };
        int smallest = Integer.MAX_VALUE;
        int s_smallest = Integer.MAX_VALUE;
        int largest = Integer.MIN_VALUE;
        int s_largest = Integer.MIN_VALUE;
        
        for(int num : arr){
            if (num < smallest) {
                s_smallest = smallest;
                smallest = num;
            } 
            else if (num > smallest && num < s_smallest) {
                s_smallest = num;
            }

            if (num > largest) {
                s_largest = largest;
                largest = num;
            } 
            else if (num < largest && num > s_largest) {
                s_largest = num;
            }

        }

        System.out.println(s_largest-s_smallest);
    }
}