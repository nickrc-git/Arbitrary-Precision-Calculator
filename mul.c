#include "apc.h"

Node* multiply(Node *a, Node *b)
{
    Node *result = create_number("0");

    int shift = 0;

    while (b)
    {
        Node *temp = NULL, *tail = NULL;
        int carry = 0;
        Node *pa = a;

        for (int i = 0; i < shift; i++)
        {
            Node *z = malloc(sizeof(Node));
            z->digit = 0;
            z->next = temp;
            temp = z;
        }

        while (pa || carry)
        {
            int prod = carry;
            if (pa)
            {
                prod += pa->digit * b->digit;
                pa = pa->next;
            }

            Node *t = malloc(sizeof(Node));
            t->digit = prod % 10;
            t->next = NULL;

            if (!temp) temp = tail = t;
            else { tail->next = t; tail = t; }

            carry = prod / 10;
        }

        Node *newres = add(result, temp);
        free_list(result);
        result = newres;

        b = b->next;
        shift++;
    }

    return result;
}
