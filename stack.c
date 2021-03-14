#include "stack.h"

void visit(Stack *s);

int main(void) {

    Stack st;
    CreateStack(&st);

    StackEntry en;

    while(!StackFull(&st)) {
        printf("Enter char for stack: ");
        scanf(" %c", &en);
        Push(en, &st);
        StackTop(&en, &st);
        printf("Stack Size: %d\n", StackSize(&st));
    }

    TraverseStack(&st, &visit);
    while(!StackEmpty(&st)){
        Pop(&thing, &st);
    }
    ClearStack(&st);
    TraverseStack(&st, &visit);
    return 0;
}

void visit(Stack *s) {
    int size = s->top-1;
    while(size >= 0) {
        printf("Stack Position: %d\t", size+1);
        printf("Stack Item: %c\n", s->entry[size]);
        size--;
    }
    fflush(stdout);
}

