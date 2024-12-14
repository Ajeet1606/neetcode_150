/**
 * problem link: https://neetcode.io/problems/string-encode-and-decode
 *
 * approach1: store lengths of each string separated by comma and append '$' at the end. add all the strings into it.
 * time: O(n)
 * space: O(n)
 */

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string ans;
        vector<int> sizes;
        for (int i = 0; i < strs.size(); i++)
        {
            int len = strs[i].length();
            sizes.push_back(len);
        }

        for (int i = 0; i < sizes.size(); i++)
        {
            ans += to_string(sizes[i]) + ",";
        }
        ans.push_back('$');
        for (int i = 0; i < strs.size(); i++)
        {
            ans += strs[i];
        }
        return ans;
    }

    vector<string> decode(string s)
    {
        vector<string> ans;
        int len = s.length();
        vector<int> sizes;
        int i;
        for (i = 0; i < s.length(); i++)
        {
            string substr;
            while (i < s.length() && s[i] != ',')
            {
                substr.push_back(s[i]);
                i++;
            }
            sizes.push_back(stoi(substr));
        }
        i++;

        for (int sz : sizes)
        {
            ans.push_back(s.substr(i, sz));
            i += sz;
        }
        return ans;
    }
};
