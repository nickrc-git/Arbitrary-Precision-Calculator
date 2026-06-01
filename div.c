#include "apc.h"

/* repeated subtraction division */
Node* divide(Node *a, Node *b)
{
    Node *count = create_number("0");
    Node *one = create_number("1");
    Node *temp = copy(a);

    while (compare(temp, b) >= 0)
    {
        Node *t = subtract(temp, b);
        free_list(temp);
        temp = t;

        Node *c = add(count, one);
        free_list(count);
        count = c;
    }

    free_list(temp);
    free_list(one);
    return count;
}
