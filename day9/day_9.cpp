/**
 * approach1: using sort
 * time: O(nlogn)
 * space: O(1)
 */

class Solution
{
public:
    int longestConsecutive(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return 0;

        int cnt = 1, ans = 1;
        sort(begin(arr), end(arr));
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1] + 1)
            {
                cnt++;
            }
            else if (arr[i] == arr[i - 1])
            {
                continue;
            }
            else
            {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};

/**
 * approach2: using set
 * time: O(n)
 * space: O(n)
 *
 * assume we start a sequence from x, and look if we've x+1, x+2 etc.. and calculate the size. before this make sure x-1 is not present, as if its was there, it would have includeded x as part of the sequence.
 */
class Solution
{
public:
    int longestConsecutive(vector<int> &arr)
    {
        unordered_set<int> s;

        for (int i = 0; i < arr.size(); i++)
            s.insert(arr[i]);

        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (s.count(arr[i] - 1) == 0)
            {
                int cnt = 1, cur = arr[i];
                while (s.count(cur + 1) > 0)
                {
                    cnt++;
                    cur++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};