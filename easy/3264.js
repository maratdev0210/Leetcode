/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} multiplier
 * @return {number[]}
 */
var getFinalState = function(nums, k, multiplier) {
    let arr = nums;
    for (let i = 0; i < k; ++i) {
        let mi = 100000, pos = -1;
        for (let j = nums.length - 1; j >= 0; --j) {
            if (arr[j] <= mi) {
                mi = arr[j];
                pos = j;
            }
        }
        arr[pos] *= multiplier;
    }
    return arr;
};