class Solution {
    private double helper(double x, long n) {
        if (x == 0) return 0;
        if (n == 0) return 1;
        double res = helper(x, n / 2);
        res = res * res;
        return (n % 2 == 0) ? res : x * res;
    }
    public double myPow(double x, int n) {
        long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return helper(x, N);
    }
}