#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "printing.h"

int main(int argc, char const *argv[]){
	unsigned char c;
	unsigned int offset = 0;

	const char *columns = argc > 1 ?argv[1] :"ohdbnru";

	if(strlen(columns) == 0 || !isalpha(columns[0])){
		printf("Usage: %s [ohdbnru]*\n", argv[0]);
		printf("\to - offset\n");
		printf("\th - hex\n");
		printf("\td - dec\n");
		printf("\tb - bin\n");
		printf("\tn - name\n");
		printf("\tr - raw\n");
		printf("\tu - utf8\n");
		return 1;
	}

	print_header(columns);

	for(c = getchar(); !feof(stdin); c = getchar()){
		print_row(offset, c, columns);
		offset++;
	}

	return 0;
}
