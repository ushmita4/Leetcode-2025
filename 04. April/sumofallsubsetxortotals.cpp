class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), count = 0;
        for (int i = 0; i < (1 << n); i++) {
            int subsetXor = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    subsetXor ^= nums[j];
                }
            }
            count += subsetXor;
        }
        return count;
    }
};
