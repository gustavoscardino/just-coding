#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> map1;
        unordered_map<string,char> map2;
        vector<string> tokens;

        int stringIt = 0;
        while(stringIt < s.size()){
            string nextToken = "";
            while(stringIt < s.size() && s[stringIt] != ' '){
                nextToken += s[stringIt];
                stringIt++;
            }
            tokens.push_back(nextToken);
            stringIt++;
        }

        if (tokens.size() != pattern.size())
            return false;

        for (int i=0; i<pattern.size(); i++){
            if (map1.find(pattern[i]) == map1.end() && map2.find(tokens[i]) == map2.end()){
                map1[pattern[i]] = tokens[i];
                map2[tokens[i]] = pattern[i];
            }
            else if(map1[pattern[i]] != tokens[i] || map2[tokens[i]] != pattern[i])
                return false;
        }
        return true;
    }
};

int main(){
    Solution sol;
    string s="abba";
    string t="dog cat cat dog";
    bool d = sol.wordPattern(s,t);
    return 0;
}