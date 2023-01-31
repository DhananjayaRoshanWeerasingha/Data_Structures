#include <stdio.h>
#include <stdlib.h>

struct node {
int data;          
struct node *next; 
}*head;

void createList(int l);
void insertNodeAtMiddle(int data, int position);
void displayList();

int main()
{
int l, data, position;

printf("Enter the number of nodes: ");
scanf("%d", &l);
createList(l);

printf("Data in the list \n");
displayList();

printf("Enter data to insert at middle of the list: ");
scanf("%d", &data);
printf("Enter the position to insert new node: " );
scanf("%d", &position);
insertNodeAtMiddle(data, position);

printf("Data in the list \n");
displayList();

return 0;
}

void createList(int n)
{
struct node *newNode, *temp;
int data, i;

head = (struct node *)malloc(sizeof(struct node));

if(head == NULL)
{
printf("Unable to allocate memory!!!");
}
else
{
printf("Enter the data node 1: ");
scanf("%d", &data);

head->data = data; 
head->next = NULL; 

temp = head;

for(i=2; i<=n; i++)
{
newNode = (struct node *)malloc(sizeof(struct node));

if(newNode == NULL)
{
printf("Unable to allocate memory!!!");
break;
}
else
{
printf("Enter the data node %d: ", i);
scanf("%d", &data);

newNode->data = data; 
newNode->next = NULL; 
temp->next = newNode; 
temp = temp->next;
}
}
printf("SUCCESSFULLY CREATED!!!\n");
}
}

void insertNodeAtMiddle(int data, int position)
{
int i;
struct node *newNode, *temp;

newNode = (struct node*)malloc(sizeof(struct node));

if(newNode == NULL)
{
printf("Unable to allocate memory!!!");
}
else
{
newNode->data = data; 
newNode->next = NULL;

temp = head;

for(i=2; i<=position-1; i++)
{
temp = temp->next;

if(temp == NULL)
break;
}

if(temp != NULL)
{
newNode->next = temp->next; 

temp->next = newNode;

printf("SUCCESSFULLY INSERTED!!!\n");
}
else
{
printf("INSERT POSITION UNABLE!!!\n");
}
}
}

void displayList()
{
struct node *temp;

if(head == NULL)
{
printf("List is empty!!!");
}
else
{
temp = head;
while(temp != NULL)
{
printf("Data -> %d\n", temp->data); 
temp = temp->next;                
}
}
}