/**
 * approach1: using map, count freq, extract this data and save in pairs format {count, number} in an array, sort the array in descending order and then return the first K elements of the array.
 * time: O(n+n+nlogn+k) -> O(nlogn)
 * space: O(n)
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        int len = arr.size();
        
        unordered_map<int, int>freq;
        for(int i=0; i<len; i++){
            freq[arr[i]]++;
        }
        vector<pair<int, int>>pairs;
        for(auto pair: freq){
            pairs.push_back({pair.second, pair.first});
        }
        vector<int>ans;
        sort(pairs.begin(), pairs.end(), greater<pair<int, int>>());
        int cnt = 0;
        while(cnt < k){
            ans.push_back(pairs[cnt].second);
            cnt++;
        }
        return ans;
    }
};

/**
 * approach2: count freq (either using map or by sorting), save the {freq, num} pair in priority_queue (max heap) and then extract top k elements.
 * time: O(nlogn)
 * space: O(n)
*/ 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        int len = arr.size();
        priority_queue<pair<int, int>>pq;
        sort(begin(arr), end(arr));
        int cur = arr[0], count = 1;
        for(int i=1; i<len; i++){
            if(arr[i] == cur){
                count++;
            }else{
                pq.push({count, cur});
                cur = arr[i];
                count = 1;
            }
        }
        pq.push({count, cur});
        vector<int>ans;
        while(k-- && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};