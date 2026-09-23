class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, pair<int,int>> freq(26);

        if (s.size() != t.size()){
            return false;
        }
        for (int i = 0; i < s.size(); i++){
            freq[s[i]].first++;
            freq[t[i]].second++;
        }
        for (int i = 0; i < s.size(); i++){
            if (freq[s[i]].first != freq[s[i]].second){
                return false;
            }
        }
        return true;
    }
};