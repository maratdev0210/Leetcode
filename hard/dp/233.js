// let dp = [
//   [12, 140, 1600, 18000, 200000, 2200000, 24000000], // [19, 199, 1999, 19999, 199999, 199]
//   [1, 20, 300, 4000],   // [9, 99, 999, 9999]
// ];

// initial state dp

let dp = [[1], [1]];

let start1 = 2,
  start2 = 10;
for (let i = 0; i < 8; i++) {
  dp[0][i + 1] = 10 * dp[0][i] + start1;
  dp[1][i + 1] = 10 * dp[1][i] + start2;
  start1 *= 10;
  start2 *= 10;
}

var count = function (digits) {
  let ans = 0,
    power = 1;
  for (let i = 0; i < digits.length; i++) {
    ans += digits[i] * power;
    power *= 10;
  }
  return ans + 1;
};

var solve = function (digits, ans) {
  for (let i = digits.length - 1; i >= 0; --i) {
    if (i == 0) {
      if (digits[i] == 0) {
        return ans;
      } else {
        return ans + 1;
      }
    }
    if (digits[i] > 2) {
      return (
        ans +
        dp[0][i] +
        (digits[i] - 2) * dp[1][i - 1] +
        solve(digits.slice(0, i), ans)
      );
    } else if (digits[i] == 2) {
      return ans + dp[0][i] + solve(digits.slice(0, i), ans);
    } else if (digits[i] == 1) {
      return (
        ans +
        dp[1][i - 1] +
        count(digits.slice(0, i)) +
        solve(digits.slice(0, i), ans)
      );
    } else {
      return ans + solve(digits.slice(0, i), ans);
    }
  }
};

var countDigitOne = function (n) {
  let digits = [];
  let n_copy = n;
  while (n_copy != 0) {
    digits.push(n_copy % 10);
    n_copy = Math.floor(n_copy / 10);
  }
  if (n == 0) {
    return 0;
  }
  let ans = 0;
  let x = solve(digits, ans);
  return x;
};





// let ans = 0;
// for (let i = 0; i <= 5349; i++) {
//   let j = i;
//   while (j != 0) {
//     if (j % 10 == 1) {
//       ans++;
//     }
//     j = Math.floor(j / 10);
//   }
// }
// console.log(ans);
