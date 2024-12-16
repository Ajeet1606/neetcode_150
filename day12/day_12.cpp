/**
 * https://leetcode.com/problems/3sum/
 * 
    Constraints:
    3 <= nums.length <= 3000
    -1e5 <= nums[i] <= 1e5

 * approach1: check all possible triplets.
 * time: O(n^3)
 * space: O(1)
 * verdict: TLE
 * 
 * approach2: 
 * sort the array
 * improve inner most loop by binarysearch.. fails on avoiding duplicates.
 * 
 * approach3:
 * sort the array
 * fix a number and search for the other two numbers using two pointers, skip duplicates on i, l, r all 3 pointers, as array is sorted, they're placed consecutively.
 * time: O(n^2)
 * space: O(1)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>>ans;
        sort(begin(arr), end(arr));
        for(int i=0; i<n; i++){
            if(arr[i]>0) break;
            if(i>0 and arr[i] == arr[i-1]) continue;
            //fixed a num, search for rest two using two pointers.
            int l = i+1, r = n-1;
            while(l<r){
                int sum = arr[i] + arr[l] + arr[r];
                if(sum > 0) r--;
                else if(sum < 0) l++;
                else{
                    ans.push_back({arr[i], arr[l], arr[r]});
                    //skip duplicates.
                    int low = arr[l], high = arr[r];
                    while(l<r && arr[l] == low) l++;
                    while(r>l && arr[r] == high) r--;
                }
            }
        }
        return ans;
    }
};

/**
 * approach4: use map, O(n^2)time + O(n)space
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>>ans;
        sort(begin(arr), end(arr));
        unordered_map<int, int>mp;

        for(int i=0; i<n; i++){
            mp[arr[i]] = i;
        }
        for(int i=0; i<n; i++){
            if(arr[i] > 0) break;
            for(int j=i+1; j<n; j++){
                int target = (-1) * (arr[i]+arr[j]);
                if(mp.count(target) && mp[target] > j){
                    ans.push_back({arr[i], arr[j], target});
                }
                j = mp.find(arr[j])->second;
            }
            i = mp.find(arr[i])->second;
        }
        return ans;
    }
};