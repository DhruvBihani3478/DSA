#include<iostream>
#include<queue>
#include<climits>
using namespace std;
class Node{
    public:
    int val;
    Node*left;
    Node*right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* insertBST(Node* root, int val) {
    if (root == NULL) return new Node(val);
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

Node* constructBST(int arr[], int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        if (arr[i] != INT_MIN) 
            root = insertBST(root, arr[i]);
    }
    return root;
}
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int maxi(Node*root){     
    if(root==NULL) return INT_MIN;
    int lmax=maxi(root->left);
    int rmax=maxi(root->right);
    return max(root->val,max(lmax,rmax));
}
int mini(Node*root){     
    if(root==NULL) return INT_MIN;
    int lmax=maxi(root->left);
    int rmax=maxi(root->right);
    return min(root->val,min(lmax,rmax));
}
int main() {
    int arr[] = {10, 5, 20, 3, 8, 15, 25, INT_MIN, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = constructBST(arr, n);
    cout << "Inorder Traversal ";
    inorder(root);
    cout << endl;
    cout<<maxi(root)<<endl;
    cout<<mini(root)<<endl;
}