#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mapS;
        unordered_map<char,int> mapT;
        int size = s.size();
        
        if (size != t.size()) return false;

        for (int i=0; i<size; i++){
            mapS[s[i]]++;
            mapT[t[i]]++;
        }

        if (mapS.size() != mapT.size()) return false;

        for (int i=0; i<size; i++){
            if (mapT.find(s[i]) == mapT.end() || mapT[s[i]] != mapS[s[i]])
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    return 0;
}