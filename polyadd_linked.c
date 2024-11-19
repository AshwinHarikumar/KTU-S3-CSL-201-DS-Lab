#include <stdio.h>
#include <stdlib.h>

struct poly {
    int coeff;
    int expo;
    struct poly* next;
};

struct poly* readpoly();
struct poly* addpoly(struct poly* p1, struct poly* p2);
void display(struct poly* p);
void freepoly(struct poly* p);

void main() {
    struct poly* p1 = readpoly();
    printf("FIRST POLYNOMIAL: ");
    display(p1);

    struct poly* p2 = readpoly();
    printf("SECOND POLYNOMIAL: ");
    display(p2);

    struct poly* p3 = addpoly(p1, p2);
    printf("RESULTANT POLYNOMIAL: ");
    display(p3);

    freepoly(p1);
    freepoly(p2);
    freepoly(p3);
}

struct poly* readpoly() {
    int t, i;
    struct poly *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter number of terms: ");
    scanf("%d", &t);
    printf("Enter coefficient and exponent in descending order:\n");

    for (i = 0; i < t; i++) {
        newNode = (struct poly*)malloc(sizeof(struct poly));
        printf("Enter coefficient %d: ", i + 1);
        scanf("%d", &newNode->coeff);
        printf("Enter exponent %d: ", i + 1);
        scanf("%d", &newNode->expo);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    return head;
}

void display(struct poly* p) {
    while (p != NULL) {
        if (p->next != NULL)
            printf("%dx^%d + ", p->coeff, p->expo);
        else
            printf("%dx^%d\n", p->coeff, p->expo);
        p = p->next;
    }
}

struct poly* addpoly(struct poly* p1, struct poly* p2) {
    struct poly *head = NULL, *temp = NULL, *newNode = NULL;

    while (p1 != NULL && p2 != NULL) {
        newNode = (struct poly*)malloc(sizeof(struct poly));
        newNode->next = NULL;

        if (p1->expo == p2->expo) {
            newNode->coeff = p1->coeff + p2->coeff;
            newNode->expo = p1->expo;
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->expo > p2->expo) {
            newNode->coeff = p1->coeff;
            newNode->expo = p1->expo;
            p1 = p1->next;
        } else {
            newNode->coeff = p2->coeff;
            newNode->expo = p2->expo;
            p2 = p2->next;
        }

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    while (p1 != NULL) {
        newNode = (struct poly*)malloc(sizeof(struct poly));
        newNode->coeff = p1->coeff;
        newNode->expo = p1->expo;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
        p1 = p1->next;
    }

    while (p2 != NULL) {
        newNode = (struct poly*)malloc(sizeof(struct poly));
        newNode->coeff = p2->coeff;
        newNode->expo = p2->expo;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
        p2 = p2->next;
    }

    return head;
}

void freepoly(struct poly* p) {
    struct poly* temp;
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
}
