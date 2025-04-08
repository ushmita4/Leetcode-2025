class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int c = 0;

        while (true) {
            unordered_set<int> unique(nums.begin(), nums.end());
            if (unique.size() == nums.size()) {
                break;
            }

          nums.erase(nums.begin(), nums.begin() + min(3, (int)nums.size()));
            c++;
        }

        return c;
    }
};
