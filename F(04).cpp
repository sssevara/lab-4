#include <iostream>
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

int cnt = 0;
class BST{
private:
    Node * root;
    Node * insert(Node * cur, int val){
        if(cur == nullptr){
            return new Node(val);
        }
        if(val > cur -> val) cur -> right = insert(cur -> right , val);
        if(val < cur -> val) cur -> left = insert(cur -> left, val);
        return cur;
    }

    void printForks(Node * cur){
        if(cur != nullptr){
            printForks(cur -> left);
            if(cur -> left && cur -> right) cnt++;
            printForks(cur -> right);
        }
    }

public:
    BST(){
        root = nullptr;
    }
    void insert(int val){
        root = insert(root, val);
    }
    void printForks(){
        printForks(root);
    }
};
int main(){
    BST tree;
    int n; cin >> n;
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        tree.insert(x);
    }
    tree.printForks();
    cout << cnt;
    return 0;
}