class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // MOST OPTIMIZED APPROACH: O(N * L log L) time, O(N * L) space
        // N = number of strings, L = max length of a string
        unordered_map<string, vector<string>> anaMap;

        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end()); // Sorting creates a unique, identical key for all anagrams
            anaMap[key].push_back(s);     // O(1) average insertion time
        }

        vector<vector<string>> result;
        // Reserve memory ahead of time to prevent dynamic reallocations
        result.reserve(anaMap.size()); 

        for (auto& pair : anaMap) {
            result.push_back(move(pair.second)); // Use 'move' to avoid copying vector data into 'result'
        }

        return result;
    }
};