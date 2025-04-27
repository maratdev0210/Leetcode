/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallerNumbersThanCurrent = function(a) {
    let n = a.length;
    let ans = new Array(n).fill(0);

    for (let i = 0; i < n; i++) {
        let cur = 0;
        for (let j = 0; j < n; j++) {
            if (a[j] < a[i]) {
                cur += 1;
            }
        }
        ans[i] = cur;
    }
    return ans;
};