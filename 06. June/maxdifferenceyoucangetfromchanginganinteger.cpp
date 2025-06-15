class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string a = s, b = s;

        for (char& c : a) {
            if (c != '9') {
                char target = c;
                for (char& ch : a) {
                    if (ch == target) ch = '9';
                }
                break;
            }
        }

       
        if (b[0] != '1') {
            char target = b[0];
            for (char& ch : b) {
                if (ch == target) ch = '1';
            }
        } else {
       
            for (int i = 1; i < b.size(); i++) {
                if (b[i] != '0' && b[i] != '1') {
                    char target = b[i];
                    for (int j = 0; j < b.size(); j++) {
                        if (b[j] == target) b[j] = '0';
                    }
                    break;
                }
            }
        }

        return stoi(a) - stoi(b);
    }
};
