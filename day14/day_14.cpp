/** https://leetcode.com/problems/trapping-rain-water/
 * approach1: find lmax and rmax for each, they work as boundaries for each bar, calculate the area of the bar.
 * time: O(n)
 * space: O(n)
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int>maxInLeft(n, 0), maxInRight(n, 0);
        int maxSoFar = 0;
        for(int i=1; i<n; i++){
            maxSoFar = max(maxSoFar, height[i-1]);
            maxInLeft[i] = maxSoFar;
        }
        maxSoFar = 0;
        for(int i=n-2; i>=0; i--){
            maxSoFar = max(maxSoFar, height[i+1]);
            maxInRight[i] = maxSoFar;
        }
        int totalWaterAmount = 0;
        for(int i=0; i<n; i++){
            cout<<height[i]<<' '<<maxInLeft[i]<<' '<<maxInRight[i]<<endl;
            int lowestBoundary = min(maxInLeft[i], maxInRight[i]);
            totalWaterAmount += max(0, lowestBoundary - height[i]);
        }
        return totalWaterAmount;
    }
};

/**
 * approach2: two pointers: use two pointers and store lmax, rmax on the fly. we've lmax for cur left and rmax for cur right, if cur left is smaller than cur right, we're sure that lmax is the boundary for cur left and cur right can work as boundary for cur right, if cur right is smaller than cur left, we're sure that rmax is the boundary for cur right and cur left can work as boundary for cur left. now just calculate the area.
 * time: O(n), space: O(1)
 * 
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int lMax = 0, rMax = 0, ans = 0;
        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left] > lMax){
                    lMax = height[left];
                }else{
                    ans += lMax - height[left];
                }
                left++;
            }else{
                if(height[right] > rMax){
                    rMax = height[right];
                }else{
                    ans += rMax - height[right];
                }
                right--;
            }
        }
        return ans;
    }
};