#include <stdio.h>  
#include <stdlib.h>  
   
struct node{  
int data;  
struct node *left;  
struct node *right;  
};  
   
struct node *root = NULL;  
struct node* createNode(int data){  
struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    
newNode->data = data;  
newNode->left = NULL;  
newNode->right = NULL;  
return newNode;  
}  
   
int findHeight(struct node *temp){  
if(root == NULL) {  
printf("Tree is empty!!!\n");  
return 0;  
}  
else {  
int leftHeight = 0, rightHeight = 0;  
          
if(temp->left != NULL)  
leftHeight = findHeight(temp->left);  
          
if(temp->right != NULL)  
rightHeight = findHeight(temp->right);  
          
int max = (leftHeight > rightHeight) ? leftHeight : rightHeight;  
return (max + 1);  
}  
}  
   
int main()  
{  
root = createNode(47);  
root->left = createNode(32);  
root->right = createNode(67);  
root->left->left = createNode(15);  
root->left->right = createNode(45);
root->right->left = createNode(9);  
root->right->right = createNode(81);  
root->left->left->left = createNode(27); 
root->left->left->right = createNode(41); 
root->left->right->left = createNode(11); 
root->left->right->right = createNode(53); 
root->right->left->left = createNode(2);  
root->right->left->right = createNode(14);  
root->right->right->left = createNode(79);    
root->right->right->right = createNode(100);  

printf("Height of the binary serch tree is %d.", findHeight(root));  
return 0;  
}  