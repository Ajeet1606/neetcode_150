/**
 * https://leetcode.com/problems/container-with-most-water/description/
 * time: O(n^2) 
 * space: O(1)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        for(int i=0; i<n; i++){
            int cur_max = 0;
            for(int j=i+1; j<n; j++){
                int amount = (j-i)* min(height[i], height[j]);
                cur_max = max(cur_max, amount);
            }
            ans = max(ans, cur_max);
        }
        return ans;
    }
};

/**
 * approach 2: two pointers
 * time: O(n)
 * space: O(1)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        int left = 0, right = n-1;
        while(left < right){
            int cur_sum = (right - left)* min(height[left], height[right]);
            ans = max(ans, cur_sum);
            if(height[left] < height[right]) left++;
            else right--;
        }
        return ans;
    }
};
//we're building a container, in the range of [left, right].
//what's the optimal condition for a point to be the end point for a start point?
// it should be on the most distant possible, it should have higher height than start.
// so left, right represent a start end. calculate its volume.
// now for the smaller height line, its done. it found a by far most point who's higher than it.
// so now we look for other remaining point, it can be either left/right.
// if left was smaller, it got its now we look for right one.
// so if left was smaller, increment left in search for a valid point for right.
// if right was smaller, decrement right in search of a valid point for left.
// on the way keep calculating the volume, when you find a potential point, its the answer for this range, increment/decrement respective pointers.