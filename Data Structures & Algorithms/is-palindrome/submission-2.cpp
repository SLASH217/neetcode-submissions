class Solution {
private: 
    bool isAlpha(char a){
        if ((48 <= a && a <= 57) || (65 <= a && a<=90) ||(97 <= a && a <=122)){
            return true;
        }
        return false;
    }
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n -1;

        while (left < right){
            if (!isAlpha(s[left])){
                left++;
                continue;
            }
            if (!isAlpha(s[right])){
                right--;
                continue;
            }
            //97 a 
            //65 A
            if (97 <= s[left] && s[left] <= 122){
                s[left] = s[left] - 32; 
            }
            if (97 <= s[right] && s[right] <= 122){
                s[right] = s[right] - 32; 
            }

            if (s[left] != s[right]){
                return false;
            }
            left++;
            right --;
        }
        return true;
    }
};
