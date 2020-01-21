#include "union.h"

int main() {

    Union* u = createUnion(10);
    printUnion(u);

    unify(u,1,2);
    unify(u,2,3);
    printUnion(u);

    free(u->data);
    free(u);
    return 0;
}