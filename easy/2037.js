/**
 * @param {number[]} seats
 * @param {number[]} students
 * @return {number}
 */
var minMovesToSeat = function(seats, students) {
    seats.sort();
    students.sort();
    let ans = 0;
    for (let i = 0; i < seats.length; i++) {
        ans += Math.abs(seats[i] - students[i]);
    }
    return ans;
};
