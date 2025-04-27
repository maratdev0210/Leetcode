/**
 * @param {number[]} nums
 * @return {number[]}
 */
var transformArray = function (nums) {
  for (let i = 0; i < nums.length; i++) {
    nums[i] %= 2;
  }
  nums.sort();
  return nums;
};
