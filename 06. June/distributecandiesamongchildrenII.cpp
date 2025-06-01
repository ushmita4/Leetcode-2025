class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long output=0;
        int min_candies=max(0,n-2*limit),max_candies=min(limit,n);
        if(min_candies>limit)
        return 0;
        for(int i=min_candies;i<=max_candies;i++)
        {
            int j=max(0,n-i-limit),k=min(n-i,limit);
            output=output+k-j+1;
        }
        return output;
    }
};
