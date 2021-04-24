class Solution {
public:
    string reverseWords(string s) {
        string curr = "";
        int count = 0;
        stack<string> storage;
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                curr += s[i];
            } else {
                if (curr != "") {
                    storage.push(curr);
                    count++;
                }
                curr = "";
            }
        }
        if (curr != "") {
            storage.push(curr);
            count++;
        }
        int i = 0;
        while (!storage.empty()) {
            i++;
            string word = storage.top();
            result += word;
            if (i != count) {
                result += " ";
            }
            storage.pop();
        }
        return result;
    }
};
