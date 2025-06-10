class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;
        
   
        for (char c : s)
            mp[c]++;

        int maxO = INT_MIN, minE = INT_MAX;
        
     
        for (auto &[ch, c] : mp) {
            if (c % 2 == 0)
                minE = min(minE, c);
            else
                maxO = max(maxO, c); 
        }

       
        if (maxO == INT_MIN || minE == INT_MAX)
            return 0;

        return maxO - minE;
    }
};
