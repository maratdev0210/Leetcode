var findMedianSortedArrays = function (nums1, nums2) {
  let nums = nums1.concat(nums2);
  nums.sort((a, b) => (a > b ? -1 : 1));

  if (nums.length % 2 == 1) {
    return nums[Math.floor(nums.length / 2)];
  } else {
    return (
      (nums[Math.floor(nums.length) / 2] +
        nums[Math.floor(nums.length) / 2 - 1]) /
      2
    );
  }
};
