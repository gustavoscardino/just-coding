#include <algorithm>  
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <unordered_map>
using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* newNode = new Node(node->val);

        unordered_map<Node*, Node*> map;
        map[node] = newNode;

        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* current = q.front(); q.pop();

            for(Node* n: current->neighbors){
                if(map.find(n) == map.end()){
                    map[n] = new Node(n->val);
                    q.push(n);
                }
                map[current]->neighbors.push_back(map[n]);
            }
        }
        return newNode;
    }
};

int main() {
    return 0;
}