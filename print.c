#include "apc.h"

void print_number(Node *h)
{
    if (!h) return;
    print_number(h->next);
    printf("%d", h->digit);
}
