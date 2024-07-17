class Solution {
public:
    int climbStairs(int n) {
        // vector<int>dp(n+1,0);
        int start=1;
        int second=1;
        for(int i=2;i<=n;i++){
            int last=start+second;
            start=second;
            second=last;
        }
        return second;
    }
};