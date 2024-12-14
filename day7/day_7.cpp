/**
 * approach1: prefix and suffix multiplication
 * time: O(n)
 * space: O(n)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(n == 2) return {nums[1], nums[0]};

        vector<int>prefix(n, 0), suffix(n, 0);
        prefix[0] = nums[0];
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] * nums[i];
        }

        suffix[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            suffix[i] = suffix[i+1] * nums[i];
        }
        vector<int>ans(n, 0);
        ans[0] = suffix[1];
        ans[n-1] = prefix[n-2];
        for(int i=1; i<n-1; i++){
            ans[i] = prefix[i-1] * suffix[i+1];
        }
        return ans;
    }
};

/**
 * same can be done without storing the prefix and suffix arrays, calculate them in run time and keep saving in result array, res[i] = prefix[i-1] and in next iteration res[i] = suffix[i+1]
*/