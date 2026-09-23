class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++){
            m[target-nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++){
            auto it = m.find(nums[i]);
            if (it != m.end() && i != m[nums[i]]){
                return {i, m[nums[i]]};
            }
        }
        return {};
    }
};
