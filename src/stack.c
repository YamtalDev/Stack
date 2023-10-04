/******************************************************************************
 * @writer:      Tal Aharon
 * @date:        01.03.2023
 
 * @description: This simple stack implementation in C provides basic stack 
 *               operations such as push, pop, peek, and more. The stack can hold 
 *               a user-specified number of elements and dynamically resizes as needed.
 * 
******************************************************************************/
#include <assert.h> /* assert       */
#include <stdio.h>  /* fprintf      */
#include <stdlib.h> /* malloc, free */

#include "stack.h"  /* Internal API */
/*****************************************************************************/
struct stack
{
	size_t capacity;
	size_t top;
	void **elements;
};

/******************************************************************************
 * @brief Creates a new stack with the given capacity.
 * @param size The maximum number of elements the stack can hold.
 * @return A pointer to the newly created stack or NULL on failure.
******************************************************************************/
stack_t *StackCreate(size_t size)
{
	stack_t *stack = (stack_t *)malloc(sizeof(stack_t) + sizeof(void *) * size);
	if(NULL == stack)
	{
		return (NULL);
	}

	stack->elements = (void **)(stack + 1);
	stack->capacity = size;
	stack->top = 0;
	return (stack);
}

/******************************************************************************
 * @brief Pushes an element onto the stack.
 * @param stack A pointer to the stack.
 * @param data  A pointer to the data to be pushed onto the stack.
******************************************************************************/
void StackPush(stack_t *stack, void *data)
{
	assert(stack && "Stack is not valid.");
	if(stack->top > stack->capacity)
	{
		return;
	}

	*((stack->elements) + (++stack->top)) = data;
}

/******************************************************************************
 * @brief Removes the top element from the stack.
 * @param stack A pointer to the stack.
******************************************************************************/
void StackPop(stack_t *stack)
{
	assert(stack && "Stack is not valid.");
	if(StackIsEmpty(stack))
	{
		return;
	}

	--(stack->top);
}

/******************************************************************************
 * @brief Retrieves the top element from the stack without removing it.
 * @param stack A pointer to the stack.
 * @return A pointer to the top element of the stack.
******************************************************************************/
void *StackPeek(stack_t *stack)
{
	assert(stack && "Stack is not valid.");
	return (*((stack->elements) + (stack->top)));
}

/******************************************************************************
 * @brief Gets the current number of elements in the stack.
 * @param stack A pointer to the stack.
 * @return The number of elements in the stack.
******************************************************************************/
size_t StackSize(stack_t *stack)
{
	assert(stack && "Stack is not valid.");
	return (stack->top);
}

/******************************************************************************
 * @brief Gets the maximum capacity of the stack.
 * @param stack A pointer to the stack.
 * @return The maximum capacity of the stack.
******************************************************************************/
size_t StackCapacity(stack_t *stack)
{
	assert(stack && "Stack is not valid.");
	return (stack->capacity);
}

/******************************************************************************
 * @brief Checks if the stack is empty.
 * @param stack A pointer to the stack.
 * @return 1 if the stack is empty, 0 otherwise.
******************************************************************************/
int StackIsEmpty(stack_t *stack)
{
	assert(stack && "Stack is not valid.");
	return stack->top == 0;
}

/******************************************************************************
 * @brief Destroys the stack and frees allocated memory.
 * @param stack A pointer to the stack.
******************************************************************************/
void StackDestroy(stack_t *stack)
{
	assert(stack && "Stack is not valid.");
	free(stack);
	stack = NULL;
}
/*****************************************************************************/

