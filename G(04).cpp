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
int maxx = 0;
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
    void inOrder(Node * cur){
        if (cur != nullptr){
            inOrder(cur -> left);
            inOrder(cur -> right);
        }
    }

    int height(Node * cur){
        if(cur == NULL) return 0;
        return max(height(cur -> left), height(cur-> right)) + 1;
    }


    int maxDist(Node * cur){
        if (cur == 0) return 0; 
        int lheight = height(cur->left); 
        int rheight = height(cur->right);
        int ldiameter = maxDist(cur->left); 
        int rdiameter = maxDist(cur->right); 
        return max(lheight + rheight + 1, max(ldiameter,rdiameter));
    }

public:
    BST(){
        root = nullptr;
    }
    void insert(int val){
        root = insert(root, val);
    }
    int maxDist(){
        return maxDist(root);
    }
    int height(){
        return height(root);
    }
};
int main(){
    BST tree;
    int n; cin >> n;
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        tree.insert(x);
    }
    cout << tree.maxDist();
    return 0;
}