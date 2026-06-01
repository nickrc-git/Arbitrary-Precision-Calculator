#include "apc.h"

int length(Node *h)
{
    int c = 0;
    while (h) { c++; h = h->next; }
    return c;
}

int compare(Node *a, Node *b)
{
    int la = length(a);
    int lb = length(b);

    if (la > lb) return 1;
    if (la < lb) return -1;

    /* same length → compare digit by digit */
    int stackA[500], stackB[500], i = 0;

    while (a) { stackA[i++] = a->digit; a = a->next; }
    i = 0;
    while (b) { stackB[i++] = b->digit; b = b->next; }

    for (int j = i - 1; j >= 0; j--)
    {
        if (stackA[j] > stackB[j]) return 1;
        if (stackA[j] < stackB[j]) return -1;
    }
    return 0;
}
