
#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node* next;
};
struct node* head = NULL;
struct node* createNode(int data) {
struct node* newNode = (struct node*)malloc(sizeof(struct node));
newNode->data = data;
newNode->next = NULL;
return newNode;
}
void createList() {
struct node* newNode, *current;
int c = 1, n, value;
printf("Enter the number of nodes: ");
scanf("%d", &n);
while (c <= n) {
newNode = (struct node*)malloc(sizeof(struct node));
printf("Enter the data: ");
scanf("%d", &value);
newNode->data = value;
newNode->next = NULL;
if (head == NULL) {
head = newNode;
current = newNode;
} else {
current->next = newNode;
current = newNode;
}
c++;
}
}
void insert_beg(int data) {
struct node* newNode = createNode(data);
newNode->next = head;
head = newNode;
}
void insert_end(int data) {
struct node* newNode = createNode(data);
if (head == NULL) {
head = newNode;
} else {
struct node* current = head;
while (current->next != NULL) {
current = current->next;
}
current->next = newNode;
}
}
void insert_pos(int data, int pos) {
struct node* newNode = createNode(data);
if (pos == 1) {
insert_beg(data);
return;
}
struct node* current = head;
struct node* previous = NULL;
int count = 1;
while (current != NULL && count < pos) {
previous = current;
current = current->next;
count++;
}
if (previous != NULL) {
newNode->next = previous->next;
previous->next = newNode;
} else {
printf("Invalid position\n");
free(newNode);
}
}
void delete_beg() {
if (head == NULL) {
printf("List is empty\n");
return;
}
struct node* current = head;
head = head->next;
free(current);
}
void delete_end() {
if (head == NULL) {
printf("List is empty\n");
return;
}
struct node* current = head;
struct node* previous = NULL;
while (current->next != NULL) {
previous = current;
current = current->next;
}
if (previous != NULL) {
previous->next = NULL;
} else {
head = NULL;
}
free(current);
}
void delete_pos(int pos) {
if (head == NULL) {
printf("List is empty\n");
return;
}
struct node* current = head;
struct node* previous = NULL;
int count = 1;
while (current != NULL && count < pos) {
previous = current;
current = current->next;
count++;
}
if (current == NULL) {
printf("Invalid position\n");
return;
}
if (previous != NULL) {
previous->next = current->next;
} else {
head = current->next;
}
free(current);
}
void display() {
struct node* current = head;
if (head == NULL) {
printf("List is empty\n");
return;
}
while (current != NULL) {
printf("%d -> ", current->data);
current = current->next;
}
printf("NULL\n");
}
int main() {
int ch, data, pos;
do {
printf("1. Create list\n");
printf("2. Insert at beginning\n");
printf("3. Insert at end\n");
printf("4. Insert at position\n");
printf("5. Delete from beginning\n");
printf("6. Delete from end\n");
printf("7. Delete from position\n");
printf("8. Display list\n");
printf("9. Exit\n");
printf("Enter your choice: ");
scanf("%d", &ch);
switch (ch) {
case 1: createList();
break;
case 2:
printf("Enter data:");
scanf("%d", &data);
insert_beg(data);
break;
case 3:
printf("Enter data:");
scanf("%d", &data);
insert_end(data);
break;
case 4:
printf("Enter data:");
scanf("%d", &data);
printf("Enter position: ");
scanf("%d", &pos);
insert_pos(data, pos);
break;
case 5:
delete_beg();
break;
case 6:
delete_end();
break;
case 7:
printf("Enter position to delete");
scanf("%d", &pos);
delete_pos(pos);
break;
case 8:
display();
break;
case 9:
printf("Exiting...\n");
break;
default:
printf("Invalid choice!\n");
}
}
while(ch!=9);
return 0;
}