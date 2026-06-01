#include "apc.h"

int main()
{
    char n1[200], n2[200];
    int ch;
    Node *a, *b, *r;

    while (1)
    {
        printf("\n1.Add 2.Sub 3.Mul 4.Div 5.Compare 6.Exit\nChoice: ");
        scanf("%d", &ch);

        if (ch == 6) break;

        printf("Enter A: "); scanf("%s", n1);
        printf("Enter B: "); scanf("%s", n2);

        a = create_number(n1);
        b = create_number(n2);

        switch (ch)
        {
        case 1: r = add(a,b); print_number(r); break;
        case 2: r = subtract(a,b); print_number(r); break;
        case 3: r = multiply(a,b); print_number(r); break;
        case 4: r = divide(a,b); print_number(r); break;
        case 5: printf("%d", compare(a,b)); break;
        }

        printf("\n");

        free_list(a);
        free_list(b);
        if (ch != 5) free_list(r);
    }
    return 0;
}
