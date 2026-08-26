class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0;
        int ones = 0;

        string ans = "";

        for (int right = 0; right < n; right++) {
            if (s[right] == '1')
                ones++;

            // Shrink while we have more than k ones
            while (left <= right && ones > k) {
                if (s[left] == '1')
                    ones--;
                left++;
            }

            // Now window has exactly k ones
            if (ones == k) {
                // Remove leading zeros to make the substring shortest
                while (left <= right && s[left] == '0') {
                    left++;
                }

                int len = right - left + 1;
                string curr = s.substr(left, len);

                if (ans.empty() ||
                    len < ans.size() ||
                    (len == ans.size() && curr < ans)) {
                    ans = curr;
                }
            }
        }

        return ans;
    }
};