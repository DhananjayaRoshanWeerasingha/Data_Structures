#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *next;
};

struct node *start = NULL;
void insert_at_begin(int);
void insert_at_end(int);
void traverse();
void delete_from_begin();
void delete_from_end();
int count = 0;

int main () {
int i,data;

for (;;) {
printf("\n1. Insert beginning element of linked list.\n");
printf("2. Insert end element of linked list.\n");
printf("3. Traverse linked list.\n");
printf("4. Delete beginning element.\n");
printf("5. Delete end element.\n");
printf("6. Exit.\n");

scanf("%d", &i);

if (i == 1) {
printf("Enter element value:");
scanf("%d", &data);
insert_at_begin(data);
}
else if (i == 2) {
printf("Enter element value:");
scanf("%d", &data);
insert_at_end(data);
}
else if (i == 3)
traverse();
else if (i == 4)
delete_from_begin();
else if (i == 5)
delete_from_end();
else if (i == 6)
break;
else
printf("\n!!!Please enter valid input!!!\n");
}
return 0;
}

void insert_at_begin(int m) {
struct node *k;

k = (struct node*)malloc(sizeof(struct node));
k->data = m;
count++;

if (start == NULL) {
start = k;
start->next = NULL;
return;
}

k->next = start;
start = k;
}

void insert_at_end(int m) {
struct node *k, *temp;

k = (struct node*)malloc(sizeof(struct node));
k->data = m;
count++;

if (start == NULL) {
start = k;
start->next = NULL;
return;
}

temp = start;

while (temp->next != NULL)
temp = temp->next;

temp->next = k;
k->next   = NULL;
}

void traverse() {
struct node *k;

k = start;

if (k == NULL) {
printf("Linked list is empty!!!\n");
return;
}

printf("There are %d elements in linked list.\n", count);

while (k->next != NULL) {
printf("%d\n", k->data);
k = k->next;
}
printf("%d\n", k->data); 
}

void delete_from_begin() {
struct node *k;
int p;

if (start == NULL) {
printf("Linked list is empty!!!\n");
return;
}

p = start->data;
k = start->next;
free(start);
start = k;
count--;

printf("%d delete beginning element successfull!!!\n", p);
}

void delete_from_end() {
struct node *k, *v;
int p;

if (start == NULL) {
printf("Linked list is empty!!!\n");
return;
}

count--;

if (start->next == NULL) {
p = start->data;
free(start);
start = NULL;
printf("%d delete successfull!!!\n", p);
return;
}

k = start;

while (k->next != NULL) {
v = k;
k = k->next;
}

p = k->data;
v->next = NULL;
free(k);

printf("%d delete successfull!!!\n", p);
}
