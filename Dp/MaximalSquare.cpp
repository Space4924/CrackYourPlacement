#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<ll>>dp(n,vector<ll>(m));
        ll answer=0;
        for(int i=0;i<m;i++){
            if(matrix[0][i]=='1')dp[0][i]=1;
            else dp[0][i]=0;
            answer=max(answer,dp[0][i]);
        }
        for(int i=0;i<n;i++){
            if(matrix[i][0]=='0')dp[i][0]=0;
            else dp[i][0]=1;
            answer=max(answer,dp[i][0]);
        }
        for(int i=1;i<n;i++){
           for(int j=1;j<m;j++){
                int maxi=INT_MAX; 
                if(matrix[i][j]=='0')dp[i][j]=0;
                else dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                answer=max(answer,dp[i][j]*dp[i][j]);
           }
        }
        return answer;
    }
};