/******************************************************************************
 * @writer:      Tal Aharon
 * @date:        01.03.2023
 *
 * @description: This header for the stack implementation in C provides basic stack
 *               operations such as push, pop, peek, and more. The stack can hold 
 *               a user-specified number of elements and dynamically resizes as needed.
 * 
 ******************************************************************************/
#ifndef __STACK_H__
#define __STACK_H__

#include <stddef.h> /* size_t, NULL */

typedef struct stack stack_t;

/******************************************************************************
 * @brief Creates a new stack with the given capacity.
 * @param size The maximum number of elements the stack can hold.
 * @return A pointer to the newly created stack or NULL on failure.
******************************************************************************/
stack_t *StackCreate(size_t );

/******************************************************************************
 * @brief Pushes an element onto the stack.
 * @param stack A pointer to the stack.
 * @param data  A pointer to the data to be pushed onto the stack.
******************************************************************************/
void StackPush(stack_t *, void *);

/******************************************************************************
 * @brief Removes the top element from the stack.
 * @param stack A pointer to the stack.
******************************************************************************/
void StackPop(stack_t *);

/******************************************************************************
 * @brief Retrieves the top element from the stack without removing it.
 * @param stack A pointer to the stack.
 * @return A pointer to the top element of the stack.
******************************************************************************/
void *StackPeek(stack_t *);

/******************************************************************************
 * @brief Gets the current number of elements in the stack.
 * @param stack A pointer to the stack.
 * @return The number of elements in the stack.
******************************************************************************/
size_t StackSize(stack_t *);

/******************************************************************************
 * @brief Gets the maximum capacity of the stack.
 * @param stack A pointer to the stack.
 * @return The maximum capacity of the stack.
******************************************************************************/
size_t StackCapacity(stack_t *);

/******************************************************************************
 * @brief Checks if the stack is empty.
 * @param stack A pointer to the stack.
 * @return 1 if the stack is empty, 0 otherwise.
******************************************************************************/
int StackIsEmpty(stack_t *);

/******************************************************************************
 * @brief Destroys the stack and frees allocated memory.
 * @param stack A pointer to the stack.
******************************************************************************/
void StackDestroy(stack_t *);

#endif /* __STACK_H__ */
