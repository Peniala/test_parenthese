#include "parenthese.h"
int main(){
	
	char expr[50] = "(())())";
	if (is_regular(expr)){
		printf("Équilibré\n");
	}
	else{
		printf("Non-équilibré\n");
	}
	return 0;
}