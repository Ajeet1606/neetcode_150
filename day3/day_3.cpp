/*
    approach1: brute force
    time: O(n^2)
    space: O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &arr, int target)
    {
        int len = arr.size();

        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (arr[i] + arr[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

/*
    approach2: using map
    time: O(n)
    space: O(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int len = arr.size();
        
        unordered_map<int, int>mp;
        
        for(int i=0; i<len; i++){
            mp[arr[i]] = i;
        }
        
        for(int i=0; i<len; i++){
            int cur = arr[i];
            int rem = target - cur;
            if(mp.find(rem) != mp.end() && mp[rem] > i){
                return {i, mp[rem]};
            }
        }
        return {};
    }
};

/**
 * approach3: using map, one iteration
 * time: O(n)
 * space: O(n)
*/
class Solution {
public: 
    vector<int> twoSum(vector<int>& arr, int target) {
        int len = arr.size();
        
        unordered_map<int, int>mp;
        
        for(int i=0; i<len; i++){
            int compliment = target - arr[i];
            if(mp.find(compliment) != mp.end()){
                return {i, mp[compliment]};
            }
            mp[arr[i]] = i;
        }
        
        return {};
    }
};