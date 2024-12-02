/**
 * approach1: using array
 * time: O(n)
 * space: O(1)
 */
class Solution {
public:
    bool isAnagram(string s, string t)
    {
        int len1 = s.length(), len2 = t.length();
        if (len1 != len2)
            return false;
        // using vector;
        vector<int> count(26, 0);

        for (int i = 0; i < len1; i++)
        {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (count[i])
                return false;
        }
        return true;
    }
};

/**
 * using map
 * time: O(n)
 * space: O(1)
 */

class Solution {
public:
    // using map.
    bool isAnagram(string s, string t)
    {
        int len1 = s.length(), len2 = t.length();
        if (len1 != len2)
            return false;

        unordered_map<int, int> mp;

        for (int i = 0; i < len1; i++)
        {
            mp[s[i]]++;
            mp[t[i]]--;
        }

        for (const auto &pair : mp)
        {
            if (pair.second != 0)
                return false;
        }
        return true;
    }
};

/**
 * using sort
 * time: O(nlogn)
 * space: O(1)
 */

class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};