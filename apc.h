#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int digit;
    struct node *next;
} Node;

Node* create_number(char *str);
Node* add(Node *a, Node *b);
Node* subtract(Node *a, Node *b);
Node* multiply(Node *a, Node *b);
Node* divide(Node *a, Node *b);
int compare(Node *a, Node *b);

void print_number(Node *head);
void free_list(Node *head);
Node* copy(Node *head);

#endif
