#include <stdio.h>

#include "main.h"
#include "ascii.h"
#include "utf8.h"

int main(int argc, char const *argv[]){
	unsigned char c;
	unsigned int i = 0;

	fprintf(stderr, "offset\thex\tdec\tbin     \tname\traw\tutf8\n");

	c = getchar();
	while(!feof(stdin)){
		printf("%d\t0x%02x\t0d%03d\t"BYTE_TO_BINARY_PATTERN"\t%s\t%c\t%s\n",
			i,
			c,
			c,
			BYTE_TO_BINARY(c),
			utf8_char_name(c),
			c,
			utf8(c));
		c = getchar();
		i++;
	}

	return 0;
}
