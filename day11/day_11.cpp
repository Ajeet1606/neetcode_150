/**
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 * time: O(n)
 * space: O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;

        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum == target){
                return {left+1, right+1};
            }
            if(sum < target){
                left++;
            }else{
                right--;
            }
        }
        return {};  //we never end up here as, there's always a soln.
    }
};

/**
 * approach1: O(n^2) brute force, search for ever pair possible.
 * approach2: O(n)time + O(n)space, search for the next element using set.
 * approach3: O(nlogn)time + O(1)space, search for the next element using binary search..
 * approach4: O(n)time + O(1)space, two pointers
*/


//approach3;
class Solution {
public:

    int search(vector<int>&numbers, int target, int left, int right){
        while (left <= right){
            int mid = right - (right - left)/2;

            if(numbers[mid] == target){
                return mid;
            }
            if(numbers[mid] > target){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size() - 1;

        for(int i=0; i<n; i++){
            int new_target = target - numbers[i];
            int target_idx = search(numbers, new_target, i+1, n);

            if(target_idx != -1){
                return {i+1, target_idx+1};
            }
        }
        return {};  //we never end up here as, there's always a soln.
    }
};
