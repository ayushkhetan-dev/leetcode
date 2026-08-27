class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Try changing target from right to left.
        // The rightmost possible change gives the smallest answer.
        for (int i = n - 1; i >= 0; i--) {

            vector<int> rem = cnt;

            // Try to match target[0...i-1]
            bool possible = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (rem[x] == 0) {
                    possible = false;
                    break;
                }

                rem[x]--;
            }

            if (!possible)
                continue;

            // At position i, choose the smallest
            // available character greater than target[i].
            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {

                if (rem[c] > 0) {
                    string ans = target.substr(0, i);

                    // Make the string strictly greater here
                    ans += char('a' + c);
                    rem[c]--;

                    // Remaining characters in sorted order
                    for (int k = 0; k < 26; k++) {
                        ans += string(rem[k], char('a' + k));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};