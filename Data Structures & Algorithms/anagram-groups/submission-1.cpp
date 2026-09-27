class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int,26> ,vector<string>>anaMap;

        for (const string& s: strs){
            array<int, 26> count = {0};
            //initialize count array as all zeroes
            for (char c: s){
                count[c - 'a'] ++;
            }
            anaMap[count].push_back(s);
        }  
        vector<vector<string>> result;
        for (auto& pair: anaMap){
            result.push_back(pair.second);
        }
        return result;
    }
};
