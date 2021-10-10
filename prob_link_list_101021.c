#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *first = NULL;

void insertion(int pos, int key)
{
    struct node *p, *q;
    p = first;
    if (pos == 0)
    {
        q = (struct node *)malloc(sizeof(struct node));
        q->data = key;
        q->next = first;
        first = q;
    }
    else
    {
        int i;
        q = (struct node *)malloc(sizeof(struct node));
        p = first;
        q->data = key;
        for (i = 0; i < pos - 1 && p != NULL; i++)
        {

            p = p->next;
        }
        q->next = p->next;
        p->next = q;
    }
}
void display()
{
    struct node *p = first;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void Rdisplay(struct node *p){

    if (p){
        printf("%d ", p->data);
        Rdisplay(p->next);
    }
}

void create(int A[], int i , int n){
    if(i == n)
        return;
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = A[i];
    temp->next = NULL;
    if(first == NULL){
        first = temp;
    }else{
        first->next = temp;
        first = first->next;
    }
    create(A,i+1,n);
}
int main()
{
    int A[] = {1, 4, 2, 5, 3, 9, 6, 7, 8};
    create(A,0 ,9);
    insertion(0, 10);
    insertion(1, 100);
    insertion(2, 1000);
    insertion(3, 10000);
    insertion(4, 100000);
    insertion(5, 1000000);

    display();
    printf("\n");
    Rdisplay(first);
    return 0;
}