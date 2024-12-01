//problem: https://leetcode.com/problems/contains-duplicate/

/*approach1

time complexity: O(n^2)
space: constant.
*/

var containsDuplicate = function (nums) {
  const len = nums.length;

  for (let idx = 0; idx < len; idx++) {
    for (let next = idx + 1; next < len; next++) {
      if (nums[idx] == nums[next]) return true;
    }
  }
  return false;
};

/*
approach2
time complexity: O(nlogn)
space: constant
*/

var containsDuplicate = function (nums) {
  const len = nums.length;

  nums.sort();
  for (let idx = 0; idx < len - 1; idx++) {
    if (nums[idx] == nums[idx + 1]) return true;
  }
  return false;
};

/*
approach3
time complexity: O(n)
space: O(n)
*/

var containsDuplicate = function (nums) {
  const len = nums.length;

  const is_seen = new Set();
  for (let cur = 0; cur < len; cur++) {
    if (is_seen.has(nums[cur])) {
      return true;
    } else {
      is_seen.add(nums[cur]);
    }
  }
  return false;
};

/*
approach4
time complexity: O(n)
space: O(n)
*/

var containsDuplicate = function (nums) {
  const len = nums.length;

  nums.sort();
  for (let idx = 0; idx < len - 1; idx++) {
    if (nums[idx] == nums[idx + 1]) return true;
  }
  return false;
};
