/**
 * approach1
 * time complexity: O(nlogn)
 * space: constant
 */

var isAnagram = function (first_string, second_string) {
  if (first_string.length != second_string.length) return false;

  const sorted_string1 = first_string.split("").sort().join("");
  const sorted_string2 = second_string.split("").sort().join("");

  return sorted_string1 == sorted_string2;
};

/**
 * approach2
 * time complexity: O(n)
 * space: constant
 */

var isAnagram = function (s, t) {
  const len1 = s.length,
    len2 = t.length;

  const frequency_map = new Map();
  for (let i = 0; i < len1; i++) {
    if (frequency_map.has(s[i])) {
      const prevValue = frequency_map.get(s[i]);
      frequency_map.set(s[i], prevValue + 1);
    } else {
      frequency_map.set(s[i], 1);
    }
  }

  for (let j = 0; j < len2; j++) {
    if (frequency_map.has(t[j])) {
      const prevValue = frequency_map.get(t[j]);
      frequency_map.set(t[j], prevValue - 1);
    } else {
      return false;
    }
  }

  for (const value of frequency_map.values()) {
    if (value != 0) return false;
  }
  return true;
};

/**
 * this can further be optimized to use single iteration for both strings as length is same.
 */
