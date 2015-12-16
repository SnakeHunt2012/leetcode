typedef struct {
    int top;
    int length;
    int *major_stack;
    int *minor_stack;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
    stack->top = -1;
    stack->length = maxSize;
    stack->major_stack = malloc(maxSize * sizeof(MinStack));
    stack->minor_stack = malloc(maxSize * sizeof(MinStack));
}

void minStackPush(MinStack *stack, int element) {
    if (stack->top < 0 || element < stack->minor_stack[stack->top])
        stack->minor_stack[stack->top + 1] = element;
    else
        stack->minor_stack[stack->top + 1] = stack->minor_stack[stack->top];
    stack->major_stack[++stack->top] = element;
}

void minStackPop(MinStack *stack) {
    --stack->top;
}

int minStackTop(MinStack *stack) {
    return stack->major_stack[stack->top];
}

int minStackGetMin(MinStack *stack) {
    return stack->minor_stack[stack->top];
}

void minStackDestroy(MinStack *stack) {
    free(stack->major_stack);
    free(stack->minor_stack);
}
