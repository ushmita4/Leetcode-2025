class Solution {
public:
    string clearDigits(string s) {
        string answer;


        for (int i = 0; i < s.size(); i++) {
   
            if (isdigit(s[i]) && !answer.empty()) {
              
                answer.pop_back();
            } else {
               
                answer += s[i];
            }
        }

        return answer;
    }
};
