class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n,0);
        if(n==0 || s[0]=='0')return 0;
        dp[0]=1;
        int i=1;
        int prev=s[0]-'0';
        while(i<n){
          int curr=s[i]-'0';
          int modified=prev*10+curr;
          if(modified<=26 && curr!=0 && prev!=0){
            if(i>1)dp[i]=dp[i-1]+dp[i-2];
            else dp[i]=1+dp[i-1];
          } else if(curr==0 && prev==0)return 0;
          else if(curr==0){
            if(modified<=20){
                if(i>1)dp[i]=dp[i-2];
                else dp[i]=dp[i-1];
            }else return false;
          }
          else dp[i]=dp[i-1];
          prev=curr;
          i++;
        }
        
        return dp[n-1];
    }
};