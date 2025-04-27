/**
 * @param {number[]} candies
 * @param {number} extraCandies
 * @return {boolean[]}
 */
var kidsWithCandies = function (candies, extraCandies) {
  let mx = candies[0];
  for (let candy of candies) {
    mx = Math.max(candy, mx);
  }
  let n = candies.length;
  let ans = new Array(n).fill(false);
  let cur = 0;
  for (let candy of candies) {
    ans[cur] = candy + extraCandies >= mx;
    cur++;
  }
  return ans;
};
