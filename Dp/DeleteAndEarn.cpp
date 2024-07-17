class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        int sum=nums[0];
        vector<int>arr;
        arr.push_back(nums[0]);
        for(int i=1;i<n;i++){
             if(nums[i]!=nums[i-1]){
             mp[nums[i-1]]=sum;
             sum=0;
             arr.push_back(nums[i]);
             }
             sum+=nums[i];
        }
        mp[nums[n-1]]=sum;
    int m=arr.size();
    for(int i=0;i<m;i++)cout<<arr[i]<<" "<<mp[arr[i]]<<"working"<<endl;
    vector<int>dp(m+1,0);
    dp[1]=mp[arr[0]];
    for(int i=2;i<=m;i++){
        if(arr[i-1]-arr[i-2]>1){
            dp[i]=dp[i-1]+mp[arr[i-1]];
        }else {
             dp[i]=max(dp[i-1],mp[arr[i-1]]+dp[i-2]);
        }
    }
    return dp[m];


    }
};