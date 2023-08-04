class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        bool answer = true;
        for (int i = 0; i < s.size(); ++i) {
            if (('a' <= s[i] && s[i] <= 'z') || ('0' <= s[i] && s[i] <= '9')) temp += s[i];
            else if ('A' <= s[i] && s[i] <= 'Z') temp += tolower(s[i]);
        }

        int size = temp.size();

        for (int i = 0; i < size / 2; ++i) {
            if (temp[i] == temp[size - i - 1]) continue;
            else {
                answer = false;
                break;
            }
        }

        return answer;
    }
};
