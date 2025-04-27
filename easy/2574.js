/**
 * @param {number[]} nums
 * @return {number[]}
 */
var leftRightDifference = function (nums) {
  let n = nums.length;
  let pref = new Array(n).fill(0);
  let suff = new Array(n).fill(0);
  for (let i = 0; i < n; i++) {
    if (i == 0) {
      pref[i] = nums[i];
    } else {
      pref[i] = pref[i - 1] + nums[i];
    }
  }
  for (let i = n - 1; i >= 0; --i) {
    if (i == n - 1) {
      suff[i] = nums[i];
    } else {
      suff[i] = suff[i + 1] + nums[i];
    }
  }
  let ans = new Array(n).fill(0);
  for (let i = 0; i < n; i++) {
    ans[i] = Math.abs(pref[i] - suff[i]);
  }
  return ans;
};
