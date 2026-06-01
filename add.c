#include "apc.h"

Node* add(Node *a, Node *b)
{
    Node *res = NULL, *tail = NULL, *t;
    int carry = 0, sum;

    while (a || b || carry)
    {
        sum = carry;
        if (a) { sum += a->digit; a = a->next; }
        if (b) { sum += b->digit; b = b->next; }

        t = malloc(sizeof(Node));
        t->digit = sum % 10;
        t->next = NULL;

        if (!res) res = tail = t;
        else { tail->next = t; tail = t; }

        carry = sum / 10;
    }
    return res;
}
