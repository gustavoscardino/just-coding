#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int windowLen = wordLen * wordCount;
        unordered_map<string, int> wordFreq;

        for (string& word : words) wordFreq[word]++;

        for (int i = 0; i < wordLen; i++) {  
            unordered_map<string, int> seen;
            int left = i, right = i;

            while (right + wordLen <= s.size()) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordFreq.count(word)) {
                    seen[word]++;

                    while (seen[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                    }

                    if (right - left == windowLen)
                        res.push_back(left);
                } else {
                    seen.clear();
                    left = right;
                }
            }
        }

        return res;
    }
};


int main() {
    Solution sol;
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","good"};
    vector<int> vec = sol.findSubstring(s,words);

    for (int i: vec){
        cout << i << endl;
    }

    return 0;
}