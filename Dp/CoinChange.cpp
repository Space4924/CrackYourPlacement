class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>dp(amount+1,1e9);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int tar=0;tar<=amount;tar++){
                if(tar-coins[i]>=0)dp[tar]=min(dp[tar],1+dp[tar-coins[i]]);   
            }
        }
        if(dp[amount]==1e9)return -1;
        else return dp[amount];
    }
};