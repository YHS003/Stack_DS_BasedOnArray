#ifndef _STACK_DS_H
#define _STACK_DS_H

#include "std_types_stack_ds.h"

#define STACK_MAX_SIZE 5
#define STACK_DEBUG

typedef struct{
    uint32 data[STACK_MAX_SIZE];
    uint32 stack_pointer;
}stack_ds;

typedef enum{
    STACK_EMPTY, /*Zero for empty*/
    STACK_FULL, /* one for full*/
    STACK_NOT_FULL /*two for not full*/
}stack_status;

/**
  *@brief  Function to initialize stack
  *@param  My_Stack pointer to the stack
  *@retval return status of the initialization
  */
return_status stack_init(stack_ds *My_Stack);

/**
  *@brief  Function to push to the stack
  *@param  My_Stack is a pointer to the stack
  *@param  value is the value to be pushed to the stack
  *@retval return status of the push process
  */
return_status stack_push(stack_ds *My_Stack, uint32 value);

/**
  *@brief  Function to pop from the stack
  *@param  My_Stack is a pointer to the stack
  *@param  value is a pointer to the value to be poped from the stack
  *@retval return status of the pop process
  */
return_status stack_pop(stack_ds *My_Stack, uint32 *value);

/**
  *@brief  Function to display the stack
  *@param  My_Stack is a pointer to the stack
  *@retval return status of the display
  */
return_status stack_display(stack_ds *My_Stack);

/**
  *@brief  Function to display the stack top
  *@param  My_Stack is a pointer to the stack
  *@param  value is a pointer to the value to be poped from the stack
  *@retval return status of the pop process
  */
return_status stack_top(stack_ds *My_Stack, uint32 *value);

/**
  *@brief  Function to Get the stack Size
  *@param  My_Stack is a pointer to the stack
  *@param  value is a pointer to the size of the stack
  *@retval return status of the pop process
  */
return_status stack_size(stack_ds *My_Stack, uint32 *stack_size);

#endif // _STACK_DS_H

