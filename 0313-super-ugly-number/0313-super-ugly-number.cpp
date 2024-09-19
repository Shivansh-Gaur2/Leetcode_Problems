#include <vector>
#include <algorithm>

class Solution {
public:
    int nthSuperUglyNumber(int n, std::vector<int>& primes) {
        std::vector<int> uglyNumbers(n);
        std::vector<int> indices(primes.size(), 0);
        std::vector<long long> nextMultiple(primes.begin(), primes.end());

        uglyNumbers[0] = 1;

        for (int i = 1; i < n; ++i) {
            long long nextUgly = *std::min_element(nextMultiple.begin(), nextMultiple.end());
            uglyNumbers[i] = nextUgly;

            for (int j = 0; j < primes.size(); ++j) {
                if (nextUgly == nextMultiple[j]) {
                    indices[j]++;
                    nextMultiple[j] = (long long)primes[j] * uglyNumbers[indices[j]];
                }
            }
        }

        return uglyNumbers[n - 1];
    }
};
