#include <stdio.h>
#include <stdlib.h>
 
struct node 
{
int key;
struct node *left, *right;
};
 
struct node* newNode(int item)
{
struct node* temp = (struct node*)malloc(sizeof(struct node));
temp->key = item;
temp->left = temp->right = NULL;
return temp;
}

void inorder(struct node* root)
{
if (root != NULL) {
inorder(root->left);
printf("%d ", root->key);
inorder(root->right);
}
}
 
struct node* insert(struct node* node, int key)
{
if (node == NULL)
return newNode(key);
if (key < node->key)
node->left = insert(node->left, key);
else
node->right = insert(node->right, key);
return node;
}
 
struct node* minValueNode(struct node* node)
{
struct node* current = node;
while (current && current->left != NULL)
current = current->left;
return current;
}
 
struct node* deleteNode(struct node* root, int key)
{
if (root == NULL)
return root;
 
if (key < root->key)
root->left = deleteNode(root->left, key);
 
else if (key > root->key)
root->right = deleteNode(root->right, key);
 
else 
{
if (root->left == NULL) {
struct node* temp = root->right;
free(root);
return temp;
}

else if (root->right == NULL) {
struct node* temp = root->left;
free(root);
return temp;
}
 
struct node*temp = minValueNode(root->right);
root->key = temp->key;
root->right = deleteNode(root->right, temp->key);
}
return root;
}
 
int main()
{
struct node* root = NULL;
root = insert(root, 25);
root = insert(root, 18);
root = insert(root, 12);
root = insert(root, 22);
root = insert(root, 28);
root = insert(root, 11);
root = insert(root, 31);
 
printf("Inorder traversal of the given tree \n");
inorder(root);
 
printf("\nDelete a leaf node\n");
root = deleteNode(root, 12);
printf("Inorder traversal of the after delete a leaf node \n");
inorder(root);
 
printf("\nDelete a single child\n");
root = deleteNode(root, 18);
printf("Inorder traversal of the after delete with a single child \n");
inorder(root);
 
printf("\nComplete delete function\n");
root = deleteNode(root, 25);
printf("Inorder traversal of the after complete delete function \n");
inorder(root);
 
return 0;
}

