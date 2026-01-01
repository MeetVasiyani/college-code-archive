class Main {
    public static void main(String[] args) {
        int n = 30;
        int m = 4;
        int k = 2;
        int quantity = n/m;
        int temp = quantity;
        while(temp >= k){
            int extra = temp/k;
            quantity += extra;
            temp = (temp%k) + extra;
        }
        System.out.println(quantity);
    }
}