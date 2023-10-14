
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
  
class Node {
public:
    int val;
    Node* left;
    Node* right;
  
    Node(int val)
    {
        this -> val = val;
        left = right = NULL;
    }
};
  
Node* create(int a[], int start, int end){
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    Node* root = new Node(a[mid]);
  
    root->left = create(a, start, mid - 1);
  
    root->right = create(a, mid + 1, end);
  
    return root;
}

void print(Node * cur){
        if (cur!= NULL){
            cout << cur -> val<< " ";
            print(cur->left);
            print(cur->right);
        }
    }

void quickSort(int *numbers, int left, int right){
    int pivot; 
    int l_hold = left; 
    int r_hold = right; 
    pivot = numbers[left];
    while (left < right) {
        while ((numbers[right] >= pivot) && (left < right)) right--;
        if (left != right){
            numbers[left] = numbers[right]; 
            left++;
        }
        while ((numbers[left] <= pivot) && (left < right)) left++; 
        if (left != right) {
            numbers[right] = numbers[left]; 
            right--; 
        }
    }
    
    numbers[left] = pivot; 
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        quickSort(numbers, left, pivot - 1);
    if (right > pivot)
        quickSort(numbers, pivot + 1, right);
}

int main(){
    int n; cin >> n;
    int num;
    int size = pow(2, n)-1;
    int arr[size];
    
    for (int i = 0; i < size; i++){
        cin >> num;
        arr[i] = num;
    }

    quickSort(arr, 0, size - 1);

    Node* root = create(arr, 0, size - 1);
  
    print(root);
    return 0;
}