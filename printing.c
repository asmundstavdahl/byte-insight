#include <stdio.h>

#include "printing.h"
#include "utf8.h"

void print_header(const char *columns){
	for(int i = 0; columns[i] != '\0'; i++){
		switch(columns[i]){
			case 'o': printf("%soffset", i ?"\t" :""); break;
			case 'h': printf("%shex", i ?"\t" :""); break;
			case 'd': printf("%sdec", i ?"\t" :""); break;
			case 'b': printf("%sbin%s", i ?"\t" :"", columns[i+1] != '\0' ?"     " :""); break;
			case 'n': printf("%sname", i ?"\t" :""); break;
			case 'r': printf("%schar", i ?"\t" :""); break;
			case 'u': printf("%sutf8", i ?"\t" :""); break;
			default: printf("<?>\t");
		}
	}
	printf("\n");
}

void print_row(unsigned int offset, unsigned char c, const char *columns){
	for(int i = 0; columns[i] != '\0'; i++){
		switch(columns[i]){
			case 'o': printf("%d\t", offset); break;
			case 'h': printf("%0x02x\t", c); break;
			case 'd': printf("%0d\t", c); break;
			case 'b': printf(""BYTE_TO_BINARY_PATTERN"\t", BYTE_TO_BINARY(c)); break;
			case 'n': printf("%s\t", utf8_char_name(c)); break;
			case 'r': printf("%c\t", c); break;
			case 'u': printf("%s\t", utf8(c)); break;
			default: printf(" ? \t");
		}
	}
	printf("\n");
}
