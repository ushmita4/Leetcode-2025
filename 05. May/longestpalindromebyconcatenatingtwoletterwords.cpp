class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> counts;
        int n = words.size();

        for (int i = 0; i < n; i++) {
            counts[words[i]]++;
        }

        int count = 0;
        bool flag = false;

        for (auto& [word, y] : counts) {
            string x = word;
            reverse(x.begin(), x.end());

            if (word == x) {
                count += (y / 2) * 4;
                if (y % 2 == 1) flag = true;
            }
            else if (counts.find(x) != counts.end()) {
                int z = counts[x];
                count += min(y, z) * 4;
                counts[word] = 0;
                counts[x] = 0;
            }
        }

        if (flag) return count + 2; 
        else return count;
    }
};
