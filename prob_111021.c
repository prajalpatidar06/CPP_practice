#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct linklist
{
    int data;
    struct linklist *link;
} node;

char ch;
node *create(node *start)
{
    node *temp, *p;
    ch = 'y';
    
    if (start != NULL)
    {
        printf("\n\t\t ** LIST ALREADY EXITS ** \n");
        getch();
        return start;
    }
    fflush(stdin);
    printf("\n\t\t * Input Block *\n");
    while (ch == 'y' || ch == 'Y')
    {
        temp = (node *)malloc(sizeof(node));
        printf("\n\tEnter the Number : ");
        scanf("%d", &temp->data);
        temp->link = NULL;

        if (start == NULL)
        {
            p = start = temp;
        }
        else
        {
            p->link = temp;
            p = temp;
        }
        fflush(stdin);
        printf("\tDo you want to continue (y/n)? : ");
        ch = getchar();
    }
    return start;
}

void print(node *start)
{
    node *temp;
    //    system("cls");
    printf("\n\n\tBase Address\t\tNumber\t\tLink");
    printf("\n\t=============================================");
    for (temp = start; temp != NULL; temp = temp->link)
    {
        printf("\n\t%10u\t%10d\t%10u", temp, temp->data, temp->link);
    }
    printf("\n\n\tPress any key to GO TO Main Block\n");
    getch();
}

// Insert AFTER A Given Node
node *insaft(node *start)
{
    node *temp, *aft;
    int dataval, item;
    aft = (node *)malloc(sizeof(node));
    printf("\n\tEnter value of Node AFTER which new node to be inserted --> ");
    scanf("%d", &dataval);
    for (temp = start; (temp->data != dataval) && (temp->link!= NULL); temp = temp->link);

    if (temp == NULL || temp->data != dataval)
    {
        printf("\n\n\tElement Not Found In LinkedList!!");
        getch();
    }
    else
    {
        printf("\n\tEnter the Element to be Insert ==> ");
        scanf("%d", &item);
        aft->data = item;
        aft->link = temp->link;
        temp->link = aft;
        printf("\n\n\tElement %d is Inserted Successfully at address %u", aft->data, aft);
        getch();
        return (start);
    }
    return (start);
}
int main()
{
    node *start, *end;
    start = NULL;
    int choice;
    while (1)
    {
        system("cls");
        printf("\t===== Main Menu =====");
        printf("\n\n\t1) Create Linked List");
        printf("\n\n\t2) Insert New Node AFTER a Given Node");
        printf("\n\n\t3) Print all Nodes of LinkedList");
        printf("\n\n\t4) Exit");
        printf("\n\n\t\tEnter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            start = create(start);
            break;

        case 2:
            start = insaft(start);
            break;

        case 3:
            print(start);
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("\n\n\tYou Entered Wrong Choice!! Retry Now");
            getch();
            break;
        }
    }
    return 0;
}