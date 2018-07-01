#include <stdio.h>
#include <string.h>

// Generate bytes from 0x00 to 0xFF

int main(int argc, char const *argv[])
{
	if(argc > 1 && !strcmp(argv[1], "reverse")){
		for (int i = 0xFF; i >= 0x00; i--)
		{
			putchar((char)i);
		}
	} else {
		for (int i = 0; i <= 0xFF; i++)
		{
			putchar((char)i);
		}
	}
	return 0;
}
