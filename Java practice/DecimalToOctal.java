class Main {
    public static void main(String[] args) {
        int decimal = 983745389;
        int temp = decimal;
        String octal = "";
        while(temp > 0){
            octal = (temp % 8) + octal;
            temp /= 8;
        }

        System.out.println(octal);
    }
}