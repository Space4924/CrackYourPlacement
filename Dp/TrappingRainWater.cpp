class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        vector<int>left;
        vector<int>right;
        int sum=0;
        for(int i=0;i<n;i++){
            sum=max(sum,arr[i]);
            left.push_back(sum);
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
             sum=max(sum,arr[i]);
             right.push_back(sum);
        }
        reverse(right.begin(),right.end());
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(right[i],left[i])-arr[i]);
        }
        return ans;
    }
};