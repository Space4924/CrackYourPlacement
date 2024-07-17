class Solution {
public:
    int maxCoins(vector<int>& arr) {
        int n=arr.size();
        arr.insert(arr.begin(),1);
        arr.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int i=0;i<n;i++)dp[i][i]=arr[i];
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j)continue;
                for(int k=i;k<=j;k++){
                    dp[i][j]=max(dp[i][j],arr[i-1]*arr[k]*arr[j+1]+dp[i][k-1]+dp[k+1][j]);
                }
            }
        }
        return dp[1][n];
    }
};