#include "stack.h"
#include "menu.h"

//void visit(Stack *s);

int main(void) {

    Stack st;
    CreateStack(&st);
    StackEntry en;

    while(TRUE)
        DoCommand(GetCommand(), &st);

    return 0;
}
/*
void visit(Stack *s) {
    int size = s->top-1;
    while(size >= 0) {
        printf("Stack Position: %d\t", size+1);
        printf("Stack Item: %c\n", s->entry[size]);
        size--;
    }
    fflush(stdout);
}
*/
