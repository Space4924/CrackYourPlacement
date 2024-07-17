class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        ans.push_back(0);
        if(n==0)return ans;
        ans.push_back(1);
        int prev=1;
        for(int i=2;i<=n;i++){
             if(i==2*prev){
                prev=i;
                ans.push_back(1);
             }
             else ans.push_back(ans[prev]+ans[i-prev]);
        }
        return ans;
    }
};