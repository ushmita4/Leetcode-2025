class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> leftToRight(n,1),rightToLeft(n,1);

        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1])
            leftToRight[i]=leftToRight[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1])
            rightToLeft[i]=rightToLeft[i+1]+1;
        }

        int totalCandies=0;
        for(int i=0;i<n;i++){
            totalCandies +=max(leftToRight[i],rightToLeft[i]);
        }
        return totalCandies;
    }
};
