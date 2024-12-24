/**
 * This file contains solutions to the problem "Best Time to Buy and Sell Stock" on LeetCode.
 * Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 * 
 * Approach 1: Brute Force
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 * 
 * Approach 2: Dynamic Programming
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * 
 * Approach 3: Optimized Dynamic Programming
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
//brute force
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ans= max(ans, prices[j] - prices[i]);
            }
        }

        return ans;
    }
};

/**
 * approach2: O(n)time + O(n)space
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0, maxSoFar = prices[n-1];
        vector<int>maxInRight(n, 0);
        for(int i=n-2; i>=0; i--){
            maxInRight[i] = maxSoFar;
            maxSoFar = max(prices[i], maxSoFar);
        }

        for(int i=0; i<n; i++){
            cout<<maxInRight[i]<<' ';
            ans = max(ans, maxInRight[i] - prices[i]);
        }
        return ans;
    }
};

/**
 * approach3: O(n)time + O(1)space
*/
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0, minSoFar = prices[0];

        for(int i=0; i<n; i++){
            minSoFar = min(minSoFar, prices[i]);
            //if I sell today
            int speculativeProfit = prices[i] - minSoFar;
            ans = max(ans, speculativeProfit);
        }
        return ans;
    }
};
