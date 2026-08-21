#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long countAmounts(long long x, vector<int>& coins) {
        long long count = 0;
        int n = coins.size();

        // Inclusion-Exclusion
        for (int mask = 1; mask < (1 << n); mask++) {
            long long L = 1;
            int bits = 0;
            bool valid = true;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    L = lcm(L, coins[i]);

                    // No multiples of L <= x
                    if (L > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid)
                continue;

            long long ways = x / L;

            if (bits % 2 == 1)
                count += ways;
            else
                count -= ways;
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = 1LL * coins[0] * k;

        // Binary Search
        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (countAmounts(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};