#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* opa(){
	char* retorno = "fala";
	return (retorno);
}

int main(){
	char test[20];

	strcpy(test, opa());

	printf("%s\n", test);
	return 0;
}