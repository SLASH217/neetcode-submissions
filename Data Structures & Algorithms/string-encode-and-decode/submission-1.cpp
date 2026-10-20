
class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";
        for (const string& str : strs) {
            // Format: [Length] + [#] + [String] -> e.g., "12#mylongstring"
            encoded_string += to_string(str.size()) + "#" + str;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_string;
        size_t i = 0;
        
        while (i < s.size()) {
            // 1. Find where the delimiter '#' is located starting from index i
            size_t j = s.find('#', i);
            
            // 2. Extract the length substring between index i and j, then convert to integer
            int len = stoi(s.substr(i, j - i));
            
            // 3. Move index past the '#' character to the start of the actual string
            i = j + 1;
            
            // 4. Extract the exact word using the length, and push to vector
            decoded_string.push_back(s.substr(i, len));
            
            // 5. Move index forward by the length of the string to process the next item
            i += len;
        }
        
        return decoded_string;
    }
};
