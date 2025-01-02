/**
 * https://leetcode.com/problems/sliding-window-maximum/description/
 * approach1: brute force: check every window and find max.
 * time: O(n^2)
 * space: O(1)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>ans(n-k+1, 0);
        int idx = 0;

        while(idx < n-k+1){
            int mx = -1e5;
            for(int i = idx; i< idx+k; i++){
                mx = max(mx, arr[i]);
            }
            ans[idx] = mx;
            idx++;
        }
        return ans;
    }
};

/**
 * approach2: priority queue
 * time: O(n)
 * space: O(k)
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        int l = 0, r = 0;
        priority_queue<pair<int, int>> pq;

        while (r < k - 1) {
            pq.push({arr[r], r});
            r++;
        }

        while (r < n) {
            pq.push({arr[r], r});
            while (pq.top().second <= r - k) {
                pq.pop();
            }
            ans.push_back(pq.top().first);
            if(arr[l] == pq.top().first && l == pq.top().second){
                pq.pop();
            }
            l++;
            r++;
        }
        return ans;
    }
};