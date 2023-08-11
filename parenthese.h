#ifndef PARENTH
#define PARENTH
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// définition de structure stack
typedef struct StackElement
{
	char value;
	struct StackElement *next;	
}StackElement, *Stack;
// prototype
Stack init_stack();
bool is_empty_stack(Stack p);
Stack push_stack(Stack p, char value);
Stack pop_stack(Stack p);
void print_stack(Stack p);
Stack clear_stack(Stack p);
bool is_regular(char* expr);

#endif