class Solution {
public:
    int productdig(int num) {
        int product = 1;
        while (num > 0) {
            int digit = num % 10;
            product *= digit;
            num /= 10;
        }
        return product;
    }

    int smallestNumber(int n, int t) {
        for (int x = n; ; x++) {
            if (productdig(x) % t == 0) {
                return x;
            }
        }
    }
};
