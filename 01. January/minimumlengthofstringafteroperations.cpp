class Solution {
public:
    int minimumLength(string s) {
    int ans = s.size();
    vector<int> freq(26, 0);
    for(auto c: s){
        freq[c - 'a']++;
        if(freq[c-'a'] != 1 && freq[c-'a'] % 2 == 1) ans -= 2;
    }
    return ans;
}
};
