/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var findPermutationDifference = function(s, t) {
    let ans = 0;
    for (let i = 0; i < s.length; i++) {
        for (let j = 0; j < t.length; j++) {
            if (t[j] == s[i]) {
                ans += Math.abs(i - j);
                break;
            }
        }
    }
    return ans;
};