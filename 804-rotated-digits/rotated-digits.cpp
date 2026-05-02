class Solution {
public:
    
    int range(int i) {
        bool diff = false;
        while (i > 0) {
            int dig = i % 10;
            // invalid digits
            if (dig == 3 || dig == 4 || dig == 7) return 0;
            // digits that change after rotation
            if (dig == 2 || dig == 5 || dig == 6 || dig == 9) diff = true;
            i /= 10;
        }
        return diff ? 1 : 0;
    }

    int rotate(int i) {
        return range(i);
    }

    int rotatedDigits(int n) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += rotate(i);
        }
        return cnt;
    }
};
