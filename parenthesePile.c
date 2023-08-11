#include "parenthese.h"
// initialiser stack
Stack init_stack(){
	return NULL;
}
bool is_empty_stack(Stack p){
	return p == NULL;
}
// ajouter elmt dans pile
Stack push_stack(Stack p, char value){
	StackElement *element;
	element = malloc(sizeof(*element));
	if (element == NULL){
		fprintf(stderr, "Erreur d'allocation dynamique\n");
		exit(EXIT_FAILURE);
	}
	element->value = value;
	element->next = p;
	return element;
}
// enlever elmt dans pile
Stack pop_stack(Stack p){
	StackElement* element;
	if(is_empty_stack(p)){
		//printf("Rien à enlever, la Pile est vide\n");
		return init_stack();
	}
	element = p->next;
	free(p);
	return element;
}
// afficher elmt dans pile
void print_stack(Stack p){
	if (is_empty_stack(p)){
		printf("Rien à afficher, la Pile est vide\n");
	}
	while(!is_empty_stack(p)){
		printf("%c ", p->value);
		p = p->next;
	}
}
//  nettoyer pile
Stack clear_stack(Stack p){
	if (is_empty_stack(p)){
		printf("Rien à liberer, la Pile est vide\n");
	}
	while(!is_empty_stack(p)){
		p = pop_stack(p);
	}
	return init_stack(p);
}
// verifier si expr equilibré
bool is_regular(char* expr){
	Stack p;
	p = init_stack();
	
	for (int i = 0; expr[i]!='\0'; ++i){
		if (expr[i]=='(' || (expr[i]==')' && is_empty_stack(p))){
			p = push_stack(p,expr[i]);
		}
		else if(expr[i]==')' && p->value=='('){
			p = pop_stack(p);
		}
	}
	bool b = is_empty_stack(p);
	p = clear_stack(p);
	return b;
}