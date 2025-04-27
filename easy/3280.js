/**
 * @param {string} date
 * @return {string}
 */
var convertDateToBinary = function (date) {
  const dates = date.split("-");
  let ans = [];
  for (let i = 0; i < dates.length; i++) {
    let num = Number(dates[i]);
    let bin = num.toString(2);
    ans.push(String(bin));
  }
  return ans.join("-");
};
