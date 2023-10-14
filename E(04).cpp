#include <iostream>
#include <cmath>
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
class BST{
private:
    Node * root;

    Node * insert(Node * cur, int x,int y,int z){
        if(cur == nullptr){
            return new Node(y);
        }
        if(z == 0 and cur -> val == x){ cur -> left = insert(cur -> left, x,y,z);
        }else if(z == 1 and cur -> val == x){cur -> right = insert(cur -> right, x,y,z);
        }
        insert(cur -> left,x,y,z);
        insert(cur -> right,x,y,z);
        return cur;
    }

    int height(Node * cur){
        if(cur == NULL) return 0;
        return max(height(cur -> left), height(cur-> right)) + 1;
    }

    void printleaves(Node * cur,int a[],int l){
        if(cur != nullptr){
            if(cur -> left != NULL){
                a[l] += 1;
            }
            if(cur -> right != NULL){
                a[l] += 1;
            }
            printleaves(cur -> left,a,l+1);
            printleaves(cur -> right,a,l+1);
        }
    }

    

public:
    BST(){
        root = nullptr;
    }

    void insert(int x,int y,int z){
        root = insert(root,x,y,z);
    }
    void printleaves(int a[],int l){
        printleaves(root,a,l);
    }
    int  height(){
        return height(root);
    }
};
int main(){
    BST tree;
    tree.insert(0,1,0);
    int size = 1;
    int n; cin >> n;
    while(n != size){
        int x,y,z;
        cin >> x >> y >> z;
        size++;
        tree.insert(x,y,z);
    }

    int h = tree.height();
    int a[h];
    for(int i = 0;i < h;i++){
        a[i] = 0;
    }
    tree.printleaves(a,0);
    std::cout << *std::max_element(a,a+h);
    return 0;
}