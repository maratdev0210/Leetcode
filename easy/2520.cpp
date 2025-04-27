class Solution {
    public:
        int countDigits(int num) {
            int ans = 0;
            int x = num;
            while (x != 0) {
                if (x == 0) {
                    break;
                }
                if (num % (x % 10) == 0) {
                    ans++;
                }
                x /= 10;
            }
            return ans;
        }
    };