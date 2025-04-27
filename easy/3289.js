/**
 * @param {number[]} nums
 * @return {number[]}
 */
var getSneakyNumbers = function (nums) {
  let n = nums.length;
  let seen = new Array(n + 2).fill(null);
  let ans = [];
  for (let num of nums) {
    if (seen[num] == null) {
      seen[num] += 1;
      continue;
    }
    if (seen[num] != null) {
      ans.push(num);
    }
  }
  return ans;
};
