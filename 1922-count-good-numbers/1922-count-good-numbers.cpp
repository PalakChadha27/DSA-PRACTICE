class Solution {
public:
    long long modPow(long long a, long long n) {
        long long mod = 1e9 + 7;
        long long ans = 1;

        while(n > 0) {
            if(n % 2 == 1)
                ans = (ans * a) % mod;

            a = (a * a) % mod;
            n /= 2;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long mod = 1e9 + 7;

        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return (modPow(5, even) * modPow(4, odd)) % mod;
    }
};