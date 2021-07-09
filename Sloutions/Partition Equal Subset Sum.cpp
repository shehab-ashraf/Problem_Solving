//time and space complexity of O(N*S) O(N∗S), where ‘N’ represents total numbers and ‘S’ is the total sum of all the numbers.
class Solution {
public:
    bool canPartition(vector<int>& nums) {
       int sum = 0,i, j;
        int n = nums.size();
        
        //sum = sum of elements in the array
        for (auto &num : nums)
            sum += num;
        
        // if 'sum' is a an odd number, we can't have two subsets with equal sum
        if (sum%2 != 0)
            return 0;
        
        // can we find subset sum(sum/2) from array?
        // we can do it easily by recursion but time complexity will be exponential
        bool dp[n+1][sum/2 +1];
        for(int i = 0 ; i <= n ; i++)
            dp[i][0] = true;
        for(int i = 1 ; i <= sum/2 ; i++)
            dp[0][i] = false;
        
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= sum/2 ; j++){
                dp[i][j] = dp[i-1][j];
                if(j >= nums[i-1]){
                    dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
         return dp[n][sum/2];
    }
};
