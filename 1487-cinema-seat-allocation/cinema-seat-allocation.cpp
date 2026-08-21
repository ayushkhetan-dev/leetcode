#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        // Store reserved seats as a bitmask for each row
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            rows[row] |= (1 << col);
        }

        // Initially, every row can accommodate 2 groups
        int ans = 2 * n;

        // Check only rows having reserved seats
        for (auto &[row, mask] : rows) {

            // We already counted 2 groups for this row,
            // so remove them and calculate the actual number.
            ans -= 2;

            // Seats 2,3,4,5
            bool left = !(mask & ((1 << 2) | (1 << 3) |
                                  (1 << 4) | (1 << 5)));

            // Seats 4,5,6,7
            bool middle = !(mask & ((1 << 4) | (1 << 5) |
                                    (1 << 6) | (1 << 7)));

            // Seats 6,7,8,9
            bool right = !(mask & ((1 << 6) | (1 << 7) |
                                   (1 << 8) | (1 << 9)));

            if (left && right) {
                // Can fit two groups: 2-5 and 6-9
                ans += 2;
            }
            else if (left || middle || right) {
                // Can fit at least one group
                ans += 1;
            }
        }

        return ans;
    }
};