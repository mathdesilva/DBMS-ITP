#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* tipo(int num){
	char* retorno;
	switch(num){
		case 1:
			return "string";
			break;
		case 2:
			return "char";
			break;
		case 3:
			return "int";
			break;
		case 4:
			return "float";
			break;
		case 5:
			return "double";
			break;
	}
}

int main(){
	printf("o tipo é %s\n", tipo(2));
	return 0;
}