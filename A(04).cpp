#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

struct Node{
    int val;
    Node * left;
    Node * right;
    Node(int val){
        this -> val = val;
        left = right = nullptr;
    }
};

struct BST{
private:
    Node * root;

    Node * push(Node * cur, int val){
        if (cur == nullptr){
            return new Node(val);
        }
        if (val < cur -> val) cur -> left = push(cur -> left, val);
        if (val > cur -> val) cur -> right = push(cur -> right, val);
        return cur;
    }

    void check(Node * cur , string s){
        int cnt = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] == 'L'){
                if(cur -> left != NULL){
                    cnt++;
                    cur = cur -> left;
                }else{
                    cout << "NO" << endl;
                    break;
                }
            }else if(s[i] == 'R'){
                if(cur -> right != NULL){
                    cnt++;
                    cur = cur -> right;
                }else{
                    cout << "NO"<< endl;
                    break;
                }
            }
        }
        if(cnt == s.size()){
            cout << "YES" << endl;
        }
    }
public:

    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }

    void check(string s){
        check(root,s);
    }
};

int main(){
    BST tree;
    int n; 
    int m;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        tree.push(x);
    }
    for(int i = 0;i < m;i++){
        string x; cin >> x;
        tree.check(x);
    }
}