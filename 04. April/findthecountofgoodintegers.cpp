class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> palindromicDigitPatterns;
        int base = pow(10, (n - 1) / 2);
        int skip = n % 2;


        for (int i = base; i < base * 10; i++) {
            string s = to_string(i);
            string reversePart = string(s.rbegin() + skip, s.rend());
            s += reversePart;
            long long palindromeNumber = stoll(s);

            if (palindromeNumber % k == 0) {
                sort(s.begin(), s.end());
                palindromicDigitPatterns.insert(s);
            }
        }

        vector<long long> factorial(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }

        long long ans = 0;
        for (const string& pattern : palindromicDigitPatterns) {
            vector<int> digitCount(10);
            for (char c : pattern) {
                digitCount[c - '0']++;
            }

          
            long long totalPermutations = 0;
            for (int firstDigit = 1; firstDigit <= 9; ++firstDigit) {
                if (digitCount[firstDigit] == 0) continue;

                digitCount[firstDigit]--;
                long long perms = factorial[n - 1];
                for (int cnt : digitCount) {
                    perms /= factorial[cnt];
                }
                totalPermutations += perms;
                digitCount[firstDigit]++;
            }

            ans += totalPermutations;
        }

        return ans;
    }
};
