class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m,vector<int>(n,0));
         vector<int>prev(n,0),curr(n,0);
        for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(i==0 && j==0)curr[j]=1;
               else if(i==0)curr[j]=curr[j-1];
               else if(j==0)curr[j]=prev[j];
               else {
                     curr[j]=prev[j]+curr[j-1];
               }
           }
           prev=curr;
        }
        return prev[n-1];
    }
};