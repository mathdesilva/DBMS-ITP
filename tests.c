#include <stdio.h>

void botar(FILE * txt){
	fprintf(txt, "fala fiote");
}

int main(){
	
	FILE * arq = fopen("opa.txt", "w");
	botar(arq);
	botar(arq);
	fclose(arq);

	return 0;
}