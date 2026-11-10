class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     //let's create a wish -> have hashmap  
        int n = nums.size();  
        unordered_set<int> hash_set(nums.begin(), nums.end());
        int longest = 0;
        for (int num : hash_set){
        //this means that num - 1 is not found in the set
            if (hash_set.find(num - 1) == hash_set.end()){
                    //if not found consider start of sequence
                    int length = 1;

                    while (hash_set.find(num + length) != hash_set.end()){
                        length++;
                    }
                    longest = max(length, longest);
                }
            }
        return longest;
    }
};
