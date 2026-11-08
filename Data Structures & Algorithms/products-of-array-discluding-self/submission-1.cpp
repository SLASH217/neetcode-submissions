class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if (n == 2){
            return {nums[1], nums[0]};
        }
        vector<int> prefix(n);
        vector<int> suffix(n);
        prefix[0] = 1;
        suffix[n - 1] = 1;
        int j = n - 2;
        for (int i = 1; i < n && j >= 0 ; i++, j--){
             prefix[i] = prefix[i - 1] * nums[i - 1];
             suffix[j] = suffix[j + 1] * nums[j + 1]; 
        }

        vector<int> result(n);
        for (int i = 0; i < n; i ++){
            result[i] = prefix[i] * suffix[i];
        }
        return result;
    }
};
