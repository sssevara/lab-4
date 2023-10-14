#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

struct Node{
    int val;
    int cnt;
    Node * left;
    Node * right;
    Node(int val){
        cnt = 1;
        this -> val = val;
        left = right = nullptr;
    }
};
class BST{
private:
    Node * root;

    Node * push(Node * cur, int val){
        if (cur == nullptr){
            Node * newNode = new Node(val);
            return newNode;
        }
        if(cur -> val == val){
            cur -> cnt++;
        }
        if (val < cur -> val) cur -> left = push(cur -> left, val);
        if (val > cur -> val) cur -> right = push(cur -> right, val);
        return cur;
    }

    void print(Node * cur,int val){
        if(cur == NULL){
            cout << 0 << endl;
            return;
        }
        if (cur -> val == val){
           cout << cur -> cnt << endl;
           return;
        }
        if(cur -> val > val){
            print(cur->left,val);
        }
        if(cur -> val < val){
            print(cur->right,val);
        }
    }

    void delation(Node * cur,int val){
        if(cur != NULL){
            if(cur -> val == val){
                if(cur->cnt > 0) cur -> cnt--;
                else cur->cnt = 0;
                return;
            }
            if(val < cur -> val) delation(cur -> left,val);
            if(val > cur -> val) delation(cur -> right,val);
        }
        return;
    }
public:

    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }

    void print(int val){
        print(root,val);
    }
    void delation(int val){
        delation(root,val);
    }
};

int main(){
    BST tree;
    int n; cin >> n;
    for(int i = 0;i < n;i++){
        string s; cin >> s;
        if(s == "insert"){
            int x; cin >> x;
            tree.push(x);
        }
        if(s == "cnt"){
            int x; cin >> x;
            tree.print(x);
        }
        if(s == "delete"){
            int x; cin >> x;
            tree.delation(x);
        }
    }
    return 0;
}