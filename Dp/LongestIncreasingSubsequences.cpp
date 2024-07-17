class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr;
        for(int i=0;i<n;i++){
            int index=lower_bound(arr.begin(),arr.end(),nums[i])-arr.begin();
            if(index==arr.size())arr.push_back(nums[i]);
            else arr[index]=nums[i];
        }
        return arr.size();
        
    }
};