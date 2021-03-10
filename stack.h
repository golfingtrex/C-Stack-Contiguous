#include "common.h"
#define MAXSTACK 10

typedef char StackEntry;
typedef struct stack {
    int top;
    StackEntry entry[MAXSTACK];
} Stack;

void CreateStack(Stack *s); /* checked */
void Push(StackEntry item, Stack *s);/* checked */
void Pop(StackEntry *item, Stack *s);/* checked */
void ClearStack(Stack *s); /* checked */
void StackTop(StackEntry *item, Stack *s);
void TraverseStack(Stack *s, void (*Visit)()); /* checked */
int StackSize(Stack *s);/* checked */
Boolean StackEmpty(Stack *s);/* checked */
Boolean StackFull(Stack *s);/* checked */

/* CreateStack
 * Pre:     None.
 * Post:    The stack s has been created and is initialized to be empty.
 * */
void CreateStack(Stack *s) {
    s->top = 0;
    for(int i=0; i<MAXSTACK; i++)
        s->entry[i] = '\0';
}


/* Push
 * Pre:     The stack exists and is not full.
 * Post:    The argument item has been stored at the top of the stack.
 * */
void Push(StackEntry item, Stack *s) {
    if(StackFull(s))
        Error("Stack is full");
    else {
        s->entry[s->top++] = item;
        //printf("Top: %d", s->top);
        //printf("Top Char: %c\n", s->entry[s->top-1]);
    }
}

/* Pop
 * Pre:     The stack exists and is not empty.
 * Post:    The top of the stack has been removed and returned in *item.
 * */
void Pop(StackEntry *item, Stack *s) {
    if(StackEmpty(s))
        Error("Stack is empty");
    else {
        *item = s->entry[--s->top];
        //printf("Top: %d", s->top);
        //printf("Top Char: %c\n", s->entry[s->top-1]);
    }
}

/* ClearStack
 * Pre:     The stack exists and its has been initialized.
 * Post:    All entries in the stack have been deleted; the stack is empty.
 * */
void ClearStack(Stack *s) {
    while(!StackEmpty(s))
        s->entry[--s->top];
}


/* StackTop
 * Pre:     The stack exists and is not empty.
 * Post:    The item at the top of the stack is returned (in *item) without
 *          being removed; the stack remains unchanged.
 * */
void StackTop(StackEntry *item, Stack *s) {
    if(StackEmpty(s))
        Error("Stack is empty");
    else
        *item = s->entry[s->top];
}

/* TraverseStack
 * Pre:     The stack exists and it has been initialized.
 * Post:    The function that Visit points to, has been invoked for each entry
 *          in the stack, beginning with the entry at the top and proceeding
 *          toward the bottom of the stack.
 * */
void TraverseStack(Stack *s, void (*Visit)()) {
    if(StackEmpty(s))
        Error("Stack is empty");
    else {
        for(int i=s->top; i>=0; i--)
            Visit();
    }
}

/* StackSize
 * Pre:     The stack exists and it has been initialized.
 * Post:    The function returns the number of entries in the stack.
 * */
int StackSize(Stack *s) {
    return s->top;
}

/* StackEmpty
 * Pre:     The stack exists and has been initialized.
 * Post:    Return TRUE if stack is empty, FALSE otherwise.
 * */
Boolean StackEmpty(Stack *s) {
    return s->top <= 0;
}

/* StackFull
 * Pre:     The stack exists and has been initialized.
 * Post:    Return TRUE if stack is full, FALSE otherwise.
 * */
Boolean StackFull(Stack *s) {
    return s->top >= MAXSTACK;
}
