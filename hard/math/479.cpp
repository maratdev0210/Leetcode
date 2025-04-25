#include <bits/stdc++.h>

using namespace std;

long long pow(long long p) {
    long long x = 1;
    for (int i = 0; i < p; i++) {
        x *= 10;
    }
    return x;
}

const long long mod = 1337;

// int main() {
//     long long n;
//     cin >> n;
//     if (n % 2 == 0) {
//         long long first = pow(n) - 1;
//         long long second = 0;
//         for (int i = n - 1; i >= n - n / 2; --i) {
//             second += 9 * pow(i);
//         }
//         second += 1;
//         long long palindrome = first * second; 
//         palindrome %= mod;
//         return 0;
//     }
//     if (n == 1) {
//         cout << 9 << endl;
//     } else if (n == 3) {
//         cout << 906609 << endl;
//     } else {
//         long long palindrome = 0;
//         for (long long i = 2 * n - 1; i >= 0; --i) {
//             if (i == 1 || i == 2 * n - 2) {
//                 continue;
//             }
//             palindrome += 9 * pow(i);
//         }
//         palindrome %= mod;
        
//     }
// }

class Solution {
    public:
        int largestPalindrome(int n) {
            if (n % 2 == 0) {
                long long first = pow(n) - 1;
                long long second = 0;
                for (int i = n - 1; i >= n - n / 2; --i) {
                    second += 9 * pow(i);
                }
                second += 1;
                long long palindrome = first * second; 
                palindrome %= mod;
                return palindrome;
            }
            if (n == 1) {
                return 9;
            } else if (n == 3) {
                return 906609 % mod;
            } else {
                long long palindrome = 0;
                for (long long i = 2 * n - 1; i >= 0; --i) {
                    if (i == 1 || i == 2 * n - 2) {
                        continue;
                    }
                    palindrome += 9ll * pow(i);
                }
                palindrome %= mod;
                return palindrome;
            }
        }
    };