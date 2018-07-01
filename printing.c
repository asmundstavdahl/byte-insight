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
			case 'r': printf("%sraw", i ?"\t" :""); break;
			case 'u': printf("%sutf8", i ?"\t" :""); break;
			default: printf("<?>\t");
		}
	}
	printf("\n");
}

void print_row(unsigned int offset, unsigned char c, const char *columns){
	for(int i = 0; columns[i] != '\0'; i++){
		switch(columns[i]){
			case 'o': printf("%s%d", i ?"\t" :"", offset); break;
			case 'h': printf("%s0x%02x", i ?"\t" :"", c); break;
			case 'd': printf("%s%0d", i ?"\t" :"", c); break;
			case 'b': printf("%s"BYTE_TO_BINARY_PATTERN"", i ?"\t" :"", BYTE_TO_BINARY(c)); break;
			case 'n': printf("%s%s", i ?"\t" :"", utf8_char_name(c)); break;
			case 'r': printf("%s%c", i ?"\t" :"", c); break;
			case 'u': printf("%s%s", i ?"\t" :"", utf8(c)); break;
			default: printf("%s ? ", i ?"\t" :"");
		}
	}
	printf("\n");
}
