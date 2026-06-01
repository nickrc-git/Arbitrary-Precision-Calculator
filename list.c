#include "apc.h"

Node* create_number(char *str)
{
    Node *head = NULL, *temp;

    for (int i = 0; str[i]; i++)
    {
        temp = malloc(sizeof(Node));
        temp->digit = str[i] - '0';
        temp->next = head;
        head = temp;
    }
    return head;
}

Node* copy(Node *head)
{
    Node *new = NULL, *tail = NULL, *temp;

    while (head)
    {
        temp = malloc(sizeof(Node));
        temp->digit = head->digit;
        temp->next = NULL;

        if (!new)
            new = tail = temp;
        else
        {
            tail->next = temp;
            tail = temp;
        }
        head = head->next;
    }
    return new;
}

void free_list(Node *head)
{
    Node *t;
    while (head)
    {
        t = head;
        head = head->next;
        free(t);
    }
}
