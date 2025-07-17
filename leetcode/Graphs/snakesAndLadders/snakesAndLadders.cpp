#include <algorithm>  
#include <iostream>
#include <vector>
#include <set>
#include <queue>
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


class Solution {
public:
    Node* cloneGraph(Node* node) {
        Node* newNode = new Node(node->val);

        set<Node*> s;
        s.insert(newNode);

        queue<Node*> q;
        q.push(node);
        queue<Node*> qCopy;
        q.push(newNode);

        while(!q.empty()){
            Node* current = q.front(); q.pop();
            Node* currentCopy = qCopy.front(); qCopy.pop();
            for(Node* n: current->neighbors){
                if(s.find(n) == s.end()){
                    Node* nCopy = new Node(n->val);
                    currentCopy->neighbors.push_back(nCopy);
                    s.insert(nCopy);
                    q.push(n);
                    qCopy.push(nCopy);
                }
                else{
                    Node* nCopy = s.
                    currentCopy->neighbors.push_back(nCopy);
                }
            }
        }
        return newNode;
    }
};

int main() {
    return 0;
}