#include <iostream>
using namespace std;
struct BstNode
{
    struct BstNode *left;
    struct BstNode *right;
    int data;
};
struct BstNode *insert(struct BstNode *root, int data)
{
    if (root == nullptr)
    {
        struct BstNode *temp = new BstNode();
        temp->data = data;
        temp->right = nullptr;
        temp->left = nullptr;
        return temp;
    }
    if (data > root->data)
    {
        root->right = insert(root->right, data);
        return root;
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
        return root;
    }
    return nullptr;
}
struct BstNode *search(struct BstNode *root, int toFindData)
{
    struct BstNode *temp = new BstNode();
    if (root == nullptr)
    {
        cout << "Empty Tree Or Value not found" << endl;
    }
    if (root->data == toFindData)
    {
        cout << " Found !! " << endl;
        temp = root;
        return temp;
    }
    if (toFindData > root->data)
    {
        search(root->right, toFindData);
        return;
    }
    if (toFindData < root->data)
    {
        search(root->left, toFindData);
        return;
    }
}
struct BstNode *deleteNode(struct BstNode *root, int data)
{
    struct BstNode *temp = new BstNode();
    struct BstNode *temp2 = new BstNode();
    temp = search(root, data);
    if (temp->left == nullptr)
    {
        temp2 = temp;
    }
}
void inOrder(struct BstNode *root)
{
    if (root != nullptr)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
int main()
{
    BstNode *root = nullptr;
    root = insert(root, 75);
    root = insert(root, 85);
    root = insert(root, 55);
    root = insert(root, 45);
    root = insert(root, 57);
    root = insert(root, 95);
    inOrder(root);
    return 0;
}