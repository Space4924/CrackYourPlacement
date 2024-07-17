class Solution {
public:
    vector<int> Rightvala(vector<int>&arr,int n){
        vector<int>ans;
        stack<int>st;
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1 && arr[st.top()]>=arr[i])st.pop();
            ans.push_back(st.top());
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<int>Leftvala(vector<int>&arr,int n){
        vector<int>ans;
        stack<int>st;
        st.push(-1);
        for(int i=0;i<n;i++){
            while(st.top()!=-1 && arr[st.top()]>=arr[i])st.pop();
            ans.push_back(st.top());
            st.push(i);
        }

        return ans;
    }
    int MaximumRectange(vector<int>&arr,int n){
        int ans=0;
        vector<int>left=Leftvala(arr,n);
        vector<int>right=Rightvala(arr,n);
        for(int i=0;i<n;i++){
            if(right[i]==-1)right[i]=n;
            ans=max(ans,(right[i]-left[i]-1)*arr[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=INT_MIN;
        vector<vector<int>>dp(n,vector<int>(m,0));
         
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && matrix[i][j]=='1')dp[i][j]=1;
                else if(i!=0 && matrix[i][j]=='1')dp[i][j]=1+dp[i-1][j];
            }
            for(int j=0;j<m;j++)cout<<dp[i][j]<<"dp";
            cout<<endl;
            ans=max(ans,MaximumRectange(dp[i],m));
         }
         return ans;
         

    }
};