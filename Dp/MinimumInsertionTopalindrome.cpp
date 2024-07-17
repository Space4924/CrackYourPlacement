class Solution {
public:
int LCS(string s,string p){
    int n=s.size();
    // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    vector<int>prev(n+1,0);
    for(int i=1;i<=n;i++){
        vector<int>curr(n+1,0);
        for(int j=1;j<=n;j++){
            if(s[i-1]==p[j-1])curr[j]=1+prev[j-1];
            else curr[j]=max(prev[j-1],max(prev[j],curr[j-1]));
        }
        prev=curr;
    }
    return prev[n];
}
    int minInsertions(string s) {
        string p=s;
        reverse(p.begin(),p.end());
        int x=LCS(p,s);
        return s.size()-x;

    }
};