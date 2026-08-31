class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

   //Alphanumeric examples: 'a', 'Z', '5', '0'

   //Non-alphanumeric examples: ' ' (space), ',', ':', '!', '@', '#'

   
        while (left < right) {
            
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};