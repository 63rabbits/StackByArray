#ifndef StackByArray_h
#define StackByArray_h

#include <stdbool.h>

//////////////////////////////////////////////////
typedef enum STACKOption {
    STACK_OPTION_NONE,
    STACK_OPTION_WITH_ELEMENT
} STACK_OPTION_e;

typedef struct Stack {
    int capacity;
    int count;
    void **array;
} Stack_t;

//////////////////////////////////////////////////
Stack_t *createStack(int capacity);
bool destroyStack(Stack_t *stack, STACK_OPTION_e option);
bool clearStack(Stack_t *stack, STACK_OPTION_e option);
bool pushStack(Stack_t *stack, void *element);
void *popStack(Stack_t *stack);
bool isEmptyStack(Stack_t *stack);

#endif
