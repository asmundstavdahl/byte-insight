#include <stdio.h>

// Binary thanks to https://stackoverflow.com/a/3208376
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

int main(int argc, char const *argv[])
{

	fprintf(stderr, "offset\thex\tdec\tbin\tASCII\n");

	unsigned char c;
	c = getchar();

	unsigned int i = 0;
	while(!feof(stdin)){
		printf("%d\t0x%02x\t0d%03d\t"BYTE_TO_BINARY_PATTERN"\t%c\n", i, c, c, BYTE_TO_BINARY(c), c);
		c = getchar();
		i++;
	}

	return 0;
}
