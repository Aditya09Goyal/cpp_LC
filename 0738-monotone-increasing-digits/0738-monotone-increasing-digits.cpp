class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int len = s.size();
        int mark = len;

        for (int i = len - 1; i > 0; i--) {
            if (s[i - 1] > s[i]) {
                s[i - 1]--;
                mark = i;
            }
        }
        for (int i = mark; i < len; i++)
            s[i] = '9';

        return stoi(s);
    }
};