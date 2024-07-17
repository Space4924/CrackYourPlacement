// Problem- https://www.geeksforgeeks.org/

int equalPartition(int n, int arr[])
    {
        int sum=0;
        for(int i=0;i<n;i++)sum+=arr[i];
        if(sum&1){
            // cout<<"NO"<<endl;
            return 0;
        }
        sort(arr,arr+n);
        int target=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int tar=0;tar<=target;tar++){
                int notTake=dp[i-1][tar];
                int take=0;
                if(tar>=arr[i-1])take=dp[i-1][tar-arr[i-1]];
                dp[i][tar]=take|notTake;
            }
        }
        if(dp[n][target]){
            // cout<<"YES"<<endl;
            return 1;
        }
        else {
            // cout<<"NO"<<endl;
            return 0;
        }
    }