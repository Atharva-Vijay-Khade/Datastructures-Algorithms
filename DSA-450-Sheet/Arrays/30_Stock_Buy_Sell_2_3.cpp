You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.



Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.


Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.





class Solution {
public:
    int mp(vector<vector<vector<int>>> &dp, vector<int> &prices, int n, int ind, int buy, int cap)       {
        
        // Base Case
        if(ind == n || cap == 0)
            return 0;
        
        if(dp[ind][buy][cap] != -1)
                return dp[ind][buy][cap];
        
        if(buy)
            return  dp[ind][buy][cap] = max(-prices[ind]+mp(dp,prices,n,ind+1,0,cap),
                                            0 + mp(dp,prices,n,ind+1,1,cap));
        else
            return dp[ind][buy][cap] = max(prices[ind]+mp(dp,prices,n,ind+1,1,cap-1),
                                            0 + mp(dp,prices,n,ind+1,0,cap));
        
    }
    int mpItr(vector<int> &prices, int n) {
        
        vector<vector<vector<int>>> dp(n+1,
                                      vector<vector<int>>(2, vector<int> (3,0)));
        
        // Base case
        for(int ind=0;ind<=n;ind++)
            for(int buy=0;buy<2;buy++)
                dp[ind][buy][0] = 0;
        
        for(int buy=0;buy<2;buy++)
            for(int cap=0;cap<3;cap++)
                dp[n][buy][cap] = 0;
        
        for(int ind = n-1;ind>=0;ind--) {
            for(int buy=0;buy<=1;buy++) {
                for(int cap=1;cap<=2;cap++) {
                    if(buy == 1)
                        dp[ind][buy][cap] = max(-prices[ind]+dp[ind+1][0][cap],
                                                             dp[ind+1][1][cap]);
                    else
                        dp[ind][buy][cap] = max(prices[ind]+dp[ind+1][1][cap-1],
                                                            dp[ind+1][0][cap]);
                }
            }
        }
        
        return dp[0][1][2];
        
    }
    int mpItrSpaceOpti(vector<int> &prices, int n) {
        
        vector<vector<int>> after(2, vector<int>(3,0));
        vector<vector<int>> cur(2, vector<int>(3,0));
        
        for(int ind = n-1;ind>=0;ind--) {
            for(int buy=0;buy<=1;buy++) {
                for(int cap=1;cap<=2;cap++) {
                    if(buy == 1)
                        cur[buy][cap] = max(-prices[ind]+after[0][cap],
                                                             after[1][cap]);
                    else
                        cur[buy][cap] = max(prices[ind]+after[1][cap-1],
                                                            after[0][cap]);
                }
            }
            after = cur;
        }
        
        return after[1][2];
        
    }
    int maxProfit(vector<int>& prices) {
        
        // vector<vector<vector<int>>> dp(prices.size(), 
        //                               vector<vector<int>>(2, vector<int> (3,-1)));
        
        return mpItrSpaceOpti(prices, prices.size());
        
    }
};