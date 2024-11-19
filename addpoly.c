#include<stdio.h>
 struct poly
 {
 int coeff;
 int expo;
 };
 int readpoly(struct poly p[]);
 int addpoly(struct poly p1[], struct poly p2[], int t1, int t2, struct poly p3[]);
void display(struct poly p[], int term);
 void main()
 {
 struct poly p1[10], p2[10], p3[10];
 int t1, t2, t3;
 t1 = readpoly(p1);
 printf("First polynomial: ");
 display(p1, t1);
 t2 = readpoly(p2);
 printf("Second polynomial: ");
 display(p2, t2);
 t3 = addpoly(p1, p2, t1, t2, p3);
 printf("Resultant polynomial: ");
 display(p3, t3);
 }
 int readpoly(struct poly p[])
 {
 int n, i;
 printf("Enter the number of terms: ");
 scanf("%d", &n);
 printf("Enter coefficient and exponent in descending order:\n");
 for (i = 0; i < n; i++)
 {
 printf("Enter coefficient %d: ", i + 1);
 scanf("%d", &p[i].coeff);
 printf("Enter exponent %d: ", i + 1);
 scanf("%d", &p[i].expo);
 }
 return n;
 }
 void display(struct poly p[], int term)
 {
 int k;
 for (k = 0; k < term - 1; k++)
 {
 printf("%dx^%d + ", p[k].coeff, p[k].expo);
 }
 printf("%dx^%d\n", p[term - 1].coeff, p[term - 1].expo);
 }
 int addpoly(struct poly p1[], struct poly p2[], int t1, int t2, struct poly p3[]) {
 int i = 0, j = 0, k = 0;
 while (i < t1 && j < t2)
 {

 if (p1[i].expo == p2[j].expo)
 {
 p3[k].coeff = p1[i].coeff + p2[j].coeff;
 p3[k].expo = p1[i].expo;
 i++;
 j++;
 k++;
 }
 else if (p1[i].expo > p2[j].expo)
 {
 p3[k].coeff = p1[i].coeff;
 p3[k].expo = p1[i].expo;
 i++;
 k++;
 }
 else
 {
 p3[k].coeff = p2[j].coeff;
 p3[k].expo = p2[j].expo;
 j++;
 k++;
 }
 }
 while (i < t1)
 {
 p3[k].coeff = p1[i].coeff;
 p3[k].expo = p1[i].expo;
 i++;
 k++;
 }
 while (j < t2)
 {
 p3[k].coeff = p2[j].coeff;
 p3[k].expo = p2[j].expo;
 j++;
 k++;
 }
 return k;
 }
