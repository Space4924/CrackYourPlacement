class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        double pref=1;
        double suff=1;
        double ans=INT_MIN;
        for(int i=0;i<n;i++){
            pref=pref*nums[i];
            suff=suff*nums[n-i-1];
            ans=max(ans,max(pref,suff));
            if(pref==0)pref=1;
            if(suff==0)suff=1;
        }
        return ans;
        
    }
};