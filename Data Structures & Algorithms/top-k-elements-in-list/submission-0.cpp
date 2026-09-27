class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> q;
        unordered_map<int, int> freqMap;
        for (auto num : nums){
            freqMap[num]++;
        }
        for (auto& [num, freq]: freqMap){
            q.push({freq, num});
        }
        vector<int> result;
        for (int i = 0; i < k; i++){
            result.push_back(q.top().second);
            q.pop();
        }
        return result;
    }
};
