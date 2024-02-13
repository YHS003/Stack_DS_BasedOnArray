#include "stack_ds.h"

int main ()
{
    stack_ds stack_1;
    uint16 test = ZERO;
    return_status retval = R_NOK;
    retval = stack_init(&stack_1);

    if(R_NOK == retval)
    {
        printf("Stack not initialized !!\n");
    }
    else
    {
        printf("Stack initialized :)\n");
        retval = stack_push(&stack_1, 1);
        retval = stack_push(&stack_1, 2);
        retval = stack_push(&stack_1, 3);
        retval = stack_push(&stack_1, 4);
        retval = stack_push(&stack_1, 5);
        retval = stack_display(&stack_1);
        retval = stack_push(&stack_1, 6);
        retval = stack_push(&stack_1, 7);
        retval = stack_push(&stack_1, 8);
        retval = stack_push(&stack_1, 9);
        retval = stack_push(&stack_1, 10);
        retval = stack_display(&stack_1);
        retval = stack_pop(&stack_1, &test);
        retval = stack_pop(&stack_1, &test);
        retval = stack_pop(&stack_1, &test);
        retval = stack_pop(&stack_1, &test);
        retval = stack_pop(&stack_1, &test);
        retval = stack_display(&stack_1);
        retval = stack_size(&stack_1, &test);
        printf("Size = %i\n", test);
    }

}
