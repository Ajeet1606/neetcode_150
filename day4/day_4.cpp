/**
 * approach 1: using sort & map
 * time: O(m * nlogn) -> m <= 1e4, n <= 100
 * space: O(m)
 */

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int len = strs.size();

        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < len; i++)
        {
            string copy = strs[i];
            sort(copy.begin(), copy.end());
            mp[copy].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            ans.push_back(itr->second);
        }
        return ans;
    }
};