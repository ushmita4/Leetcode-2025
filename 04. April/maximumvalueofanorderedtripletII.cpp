class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res=0,maxele=0,maxsub=0;
        for(int i=0;i<nums.size();i++){
            res=max(res,1LL*maxsub*nums[i]);
            maxsub=max(maxsub,maxele-nums[i]);
            maxele=max(maxele,1LL*nums[i]);
        }
        return res;
    }
};
