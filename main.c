#include <stdio.h>
#include <stdlib.h>

#include "printing.h"

int main(int argc, char const *argv[]){
	unsigned char c;
	unsigned int offset = 0;

	const char *columns = argc > 1 ?argv[1] :"ohdbnru";

	print_header(columns);

	for(c = getchar(); !feof(stdin); c = getchar()){
		print_row(offset, c, columns);
		offset++;
	}

	return 0;
}
