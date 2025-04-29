/**
 * @param {number} n
 * @return {boolean}
 */
var isStrictlyPalindromic = function (n) {
  for (let i = 2; i <= n - 2; ++i) {
    let str = n.toString(i);
    for (let j = 0; j < str.length; j++) {
      if (str[j] !== str[str.length - j - 1]) {
        return false;
      }
    }
  }
  return true;
};
