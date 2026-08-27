class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26, 0);
        int maxCount = 0;
        char maxChar = 'a';

        for (char c : s) {
            count[c - 'a']++;
            if (count[c - 'a'] > maxCount) {
                maxCount = count[c - 'a'];
                maxChar = c;
            }
        }

        if (maxCount > (s.length() + 1) / 2) {
            return "";
        }

        string result = s;
        int index = 0;

        while (count[maxChar - 'a'] > 0) {
            result[index] = maxChar;
            index += 2;
            count[maxChar - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            while (count[i] > 0) {
                if (index >= s.length()) {
                    index = 1;
                }
                result[index] = (char)('a' + i);
                index += 2;
                count[i]--;
            }
        }

        return result;
    }
};