/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumOperations = function (nums) {
  let cnt = 0;
  for (let i = 0; i < nums.length; i++) {
    let r = nums[i] % 3;
    if (r == 0) {
      continue;
    }
    cnt += 1;
  }
  return cnt;
};
