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
int maxDepth(Node* root) {
    if(root==NULL) return 0;
    return 1+max(maxDepth(root->left),maxDepth(root->right));
}
int minDepth(Node* root) {
        if (root == NULL) return 0;
        if (root->left == NULL)return 1 + minDepth(root->right);
        if (root->right == NULL)return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
int main() {
    int arr[] = {10, 5, 20, 3, 8, 15, 25, INT_MIN, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = constructBST(arr, n);
    cout << "Inorder Traversal ";
    inorder(root);
    cout << endl;
    cout<<maxDepth(root);
    cout << endl;
    cout<<minDepth(root);
    cout << endl;
}