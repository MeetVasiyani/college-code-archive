class Main {
    static int findNthDigit(int n) {
        String s = "";
        int num = 1;

        while (s.length() < n) {
            s += num;
            num++;
        }

        return s.charAt(n - 1) - '0';
    }

    public static void main(String[] args) {
        int n = 11;
        System.out.println(findNthDigit(n));
    }
}
