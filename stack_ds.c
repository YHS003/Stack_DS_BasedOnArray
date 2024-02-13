#include "stack_ds.h"

/**
  *@brief  Function to initialize stack
  *@param  My_Stack pointer to the stack
  *@retval return status of the initialization
  */
return_status stack_init(stack_ds *My_Stack)
{
    return_status retval = R_NOK;

    if(NULL == My_Stack)
    {
        retval = R_NOK;
    }
    else
    {
        My_Stack->stack_pointer = -1;
        retval = R_OK;
    }

    return retval;
}

/**
  *@brief  Function to check stack is full or not
  *@param  My_Stack pointer to the stack
  *@retval return status of the stack
  */
static stack_status stack_full(stack_ds *My_Stack)
{
    stack_status retval = STACK_EMPTY;

    if((STACK_MAX_SIZE - 1) == My_Stack->stack_pointer)
    {
        retval = STACK_FULL;
    }
    else
    {
        retval = STACK_NOT_FULL;
    }

    return retval;
}

/**
  *@brief  Function to check stack is empty or not
  *@param  My_Stack pointer to the stack
  *@retval return status of the stack
  */
static stack_status stack_empty(stack_ds *My_Stack)
{
    stack_status retval = STACK_EMPTY;

    if(-1 == My_Stack->stack_pointer)
    {
        retval = STACK_EMPTY;
    }
    else
    {
        retval = STACK_NOT_FULL;
    }

    return retval;
}

/**
  *@brief  Function to push to the stack
  *@param  My_Stack is a pointer to the stack
  *@param  value is the value to be pushed to the stack
  *@retval return status of the push process
  */
return_status stack_push(stack_ds *My_Stack, uint32 value)
{
    return_status retval = R_NOK;

    if((NULL == My_Stack) || (STACK_FULL == stack_full(My_Stack)))
    {
        retval = R_NOK;
    }
    else
    {
        My_Stack->stack_pointer++;
        My_Stack->data[My_Stack->stack_pointer] = value;
        retval = R_OK;
    }

    return retval;
}

/**
  *@brief  Function to display the stack
  *@param  My_Stack is a pointer to the stack
  *@retval return status of the display
  */
return_status stack_display(stack_ds *My_Stack)
{
    return_status retval = R_NOK;
    sint32 counter = ZERO_INIT;
    if((NULL == My_Stack) || (STACK_EMPTY == stack_empty(My_Stack)))
    {
        retval = R_NOK;
    }
    else
    {
        printf("Stack Data: ");
        for(counter = My_Stack->stack_pointer; counter >= ZERO; counter--)
        {
            printf("%i\t",My_Stack->data[counter]);
        }
        printf("\n");
        retval = R_OK;
    }

    return retval;
}

/**
  *@brief  Function to pop from the stack
  *@param  My_Stack is a pointer to the stack
  *@param  value is a pointer to the value to be poped from the stack
  *@retval return status of the pop process
  */
return_status stack_pop(stack_ds *My_Stack, uint32 *value)
{
    return_status retval = R_NOK;

    if((NULL == My_Stack) || (NULL == value) || (STACK_EMPTY == stack_empty(My_Stack)))
    {
        retval = R_NOK;
    }
    else
    {
        *value = My_Stack->data[My_Stack->stack_pointer];
        My_Stack->stack_pointer--;
        retval = R_OK;
        #ifdef STACK_DEBUG
        printf("Value (%i) is poped..\n",*value);
        #endif // STACK_DEBUG
    }

    return retval;
}

/**
  *@brief  Function to display the stack top
  *@param  My_Stack is a pointer to the stack
  *@param  value is a pointer to the value to be poped from the stack
  *@retval return status of the pop process
  */
return_status stack_top(stack_ds *My_Stack, uint32 *value)
{
    return_status retval = R_NOK;

    if((NULL == My_Stack) || (NULL == value) || (STACK_EMPTY == stack_empty(My_Stack)))
    {
        retval = R_NOK;
    }
    else
    {
        *value = My_Stack->data[My_Stack->stack_pointer];
        retval = R_OK;
    }

    return retval;
}

/**
  *@brief  Function to Get the stack Size
  *@param  My_Stack is a pointer to the stack
  *@param  value is a pointer to the size of the stack
  *@retval return status of the pop process
  */
return_status stack_size(stack_ds *My_Stack, uint32 *stack_size)
{
    return_status retval = R_NOK;

    if((NULL == My_Stack) || (NULL == stack_size))
    {
        retval = R_NOK;
    }
    else
    {
        *stack_size = My_Stack->stack_pointer + 1;
        retval = R_OK;
    }

    return retval;
}
