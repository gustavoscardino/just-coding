#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class RandomizedSet {
    unordered_map<int, int> map;
    vector<int> values;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (map.count(val)) return false;
        values.push_back(val);
        map[val] = values.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if (!map.count(val)) return false;
        
        int index = map[val];
        swap(values[index], values[values.size() - 1]);
        map[values[index]] = index;
        map.erase(val);
        values.pop_back();      
        return true;
    }
    
    int getRandom() {
        int index = rand() % values.size();
        return values[index];
    }
};


int main() {
    return 0;
}