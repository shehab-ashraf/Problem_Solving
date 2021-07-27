//O(N^2) time || O(n) space
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& array) {
        int targetSum = 0;
        vector<vector<int>> result;
	    sort(array.begin(),array.end());
	    for(int i = 0 ; i < array.size() ; i++) {
            if(i > 0 && array[i] == array[i-1]) continue;
		    int left = i+1;
		    int right = array.size() -1;
		    while(right > left) {
                int CurrentSum = array[left] + array[right] + array[i];
			    if(CurrentSum == targetSum) {
                    vector<int> temp = {array[i], array[left] , array[right] };
				     result.push_back(temp);
                     while(left<right && array[left]==array[left+1])    
                         left++;
                     while(left<right && array[right]==array[right-1]) 
                         right--;
                     right--;
                     left++;
                 }
                 else { 
                 	if(CurrentSum > targetSum) right--;
				    else left++;
				}
			}
		}
		return result;  
    }
};
