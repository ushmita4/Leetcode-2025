class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        sort(nums.rbegin(), nums.rend());
        
        int c = 0;
        int n = nums.size();

      
        for (int num : nums) {
            if (num < k) {
                return -1;
            }
        }

   
        int i = 0;
        while (i < n) {
            if (nums[i] == k) 
                break; 
            int h = nums[i];      
            while (i < n && nums[i] == h) {
                nums[i] = k;       
                i++;
            }
        c++;        
        }

        
        for (int num : nums) {
            if (num != k) {
                return -1;
            }
        }

        return c;
    }
};
