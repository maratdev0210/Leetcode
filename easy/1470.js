/**
 * @param {number[]} nums
 * @param {number} n
 * @return {number[]}
 */
var shuffle = function(nums, n) {
    let ans = new Array(2 * n).fill(null);
    for (let i = 0; i < n; i++) {
        ans[i * 2] = nums[i];
        ans[i * 2 + 1] = nums[n + i];
    }
    return ans;
};