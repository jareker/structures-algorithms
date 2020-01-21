
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Union Union;

struct Union
{
    size_t size;
    int *data;
    int *tree_size;
};

Union *createUnion(size_t size)
{
    Union *u = (Union *)malloc(sizeof(Union));
    u->size = size;
    u->data = calloc(size, sizeof(int));
    u->tree_size = calloc(size, sizeof(int));

    for (int i = 0; i < size; ++i)
    {
        u->data[i] = i;
        u->tree_size[i] = 1;
    }

    return u;
}

void printUnion(Union *u)
{
    for (int i = 0; i < u->size; ++i)
    {
        printf("%d ", u->data[i]);
    }
    printf("\n");
}

// we can call a value as 'the root' when an index and a value are the same
// so we iterate through all values until condition is met
int root(Union *u, int i)
{
    while (u->data[i] != i)
    {
        i = u->data[i];
    }

    return i;
}

// two values are connected when their roots are the same
int areConnected(Union *u, int p, int q)
{
    return root(u, p) == root(u, q);
}

// connects two elements into union by change a root of one of them
void unify(Union *u, int p, int q)
{
    int i = root(u, p);
    int j = root(u, q);
    int *x = &u->tree_size[i];
    int *y = &u->tree_size[j];
    if (i == j)
        return;
    if (*x < *y)
    {
        u->data[i] = j;
        (*y) += (*x);
    }
    else
    {
        u->data[j] = i;
        (*x) += (*y);
    }
}
