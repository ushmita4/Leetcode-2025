class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            int difference=abs(nums[i]-nums[(i+1)%n]);
            maxi=max(difference,maxi);
        }
        return maxi;
    }
};
