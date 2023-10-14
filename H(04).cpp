#include <iostream>
using namespace std;

struct Node{
    int val;
    Node * left;
    Node * right;

    Node(int val){
        this -> val = val;
        left = right = NULL;
    }
};
int cnt = 0;
class BST{
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


    void print(Node * cur){
        if(cur != NULL){
            print(cur -> right);
            cout << cur -> val + cnt << " ";
            cnt += cur -> val;
            print(cur -> left);
        }
    }
public:

    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }

    void print (){
        print(root);
    }
};

int main(){
    BST tree;
    int n; cin >> n;
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        tree.push(x);
    }
    tree.print();
    return 0;
}