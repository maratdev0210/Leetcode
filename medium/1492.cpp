class Solution {
public:
    int kthFactor(int n, int k) {
        vector <int> d;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (n / i == i) {
                    d.push_back(i);
                } else {
                    d.push_back(i);
                    d.push_back(n / i);
                }
            }
        }
        if (d.size() < k) {
            return -1;
        }
        sort(d.begin(), d.end());
        return d[k - 1];
    }
};