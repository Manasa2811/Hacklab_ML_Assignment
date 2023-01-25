#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node *next;
};



void add(struct Node** head, int data){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    printf("Added %d\n",newNode->data);
}

void deletePos ( int pos)
{
    struct Node* head;
    struct Node* temp = head;
    int i;
    if (pos == 0) {
        printf("\nElement deleted is : %d\n", temp->data);
        head = head->next;
        temp->next = NULL;
        free(temp);
    }
    else {
        for (i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }

        struct Node* del
            = temp->next;
        temp->next = temp->next->next;
        printf("\nElement deleted is : %d\n", del->data);
        del->next = NULL;
        free(del);
 }
}
void deleteAll()
{
    struct Node *temp;


    struct Node *head;
    while(head != NULL)
    {
        temp = head;
        head = head->next;

        free(temp);
    }

    printf("SUCCESSFULLY DELETED\n");
}

void display(struct Node* node)
{
    printf("Linked List: ");
    while(node!=NULL){
        printf("%d ",node->data);
        node = node->next;
    }

    printf("\n");
}
int main()
{
    struct Node* head = NULL;


    add(&head,100);
    add(&head,80);
    add(&head,60);
    display(head);

    deletePos(1);
    deleteAll();
    display(head);

    return 0;
}
