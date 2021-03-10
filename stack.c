#include "stack.h"

void hi();

int main(void) {

    Stack st;
    CreateStack(&st);

    StackEntry en;

    while(StackSize(&st)<MAXSTACK) {
        Push('a', &st);
        StackTop(&en, &st);
    }
    ClearStack(&st);

    return 0;
}

void hi() {
    printf("hi\n");
}

