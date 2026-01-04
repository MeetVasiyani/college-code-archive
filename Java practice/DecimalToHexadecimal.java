class Main {
    public static void main(String[] args) {
        int decimal = 983745389;
        char [] ch = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
        int temp = decimal;
        String hex = "";
        while(temp > 0){
            int rem = temp%16;
            hex = ch[rem] + hex;
            temp /= 16;
        }

        System.out.println(hex);
    }
}