#include "apc.h"

Node* subtract(Node *a, Node *b)
{
    Node *res = NULL, *tail = NULL, *t;
    int borrow = 0, diff;

    while (a)
    {
        diff = a->digit - borrow;
        if (b) { diff -= b->digit; b = b->next; }

        if (diff < 0) { diff += 10; borrow = 1; }
        else borrow = 0;

        t = malloc(sizeof(Node));
        t->digit = diff;
        t->next = NULL;

        if (!res) res = tail = t;
        else { tail->next = t; tail = t; }

        a = a->next;
    }
    return res;
}
