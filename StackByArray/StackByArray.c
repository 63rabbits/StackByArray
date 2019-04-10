#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include "StackByArray.h"

//////////////////////////////////////////////////
Stack_t *createStack(int capacity) {
    // Block illegal parameters.
    if (capacity <= 0) return NULL;
    
    Stack_t *stack = malloc(sizeof(Stack_t));
    if (stack == NULL) return NULL;
    stack->array = malloc(capacity * sizeof(void*));
    if (stack->array == NULL) {
        free(stack);
        return NULL;
    }
    stack->count = 0;
    stack->capacity = capacity;
    
    return stack;
}

bool destroyStack(Stack_t *stack, STACK_OPTION_e option) {
    // Block illegal parameters.
    if (stack == NULL) return false;
    
    clearStack(stack, option);
    if (stack->array != NULL) {
        free(stack->array);
    }
    free(stack);
    
    return true;
}

bool clearStack(Stack_t *stack, STACK_OPTION_e option) {
    // Block illegal parameters.
    if (stack == NULL) return false;
    
    if (option != STACK_OPTION_WITH_ELEMENT) return true;
    
    while (true) {
        void *element = popStack(stack);
        if (element == NULL) break;
        free(element);
    }
    
    return true;
}

bool pushStack(Stack_t *stack, void *element) {
    // Block illegal parameters.
    if (stack == NULL) return false;
    if (element == NULL) return false;
    
    if ((stack->count + 1) > stack->capacity) {
        return false;
    }
    stack->array[stack->count] = element;
    stack->count++;
    
    return true;
}

void *popStack(Stack_t *stack) {
    // Block illegal parameters.
    if (stack == NULL) return NULL;
    
    if (stack->count <= 0) {
        return NULL;
    }
    stack->count--;
    void *element = stack->array[stack->count];
    
    return element;
}

bool isEmptyStack(Stack_t *stack) {
    if (stack == NULL) return true;
    
    if (stack->count <= 0) return true;
    return false;
}
