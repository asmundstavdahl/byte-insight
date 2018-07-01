#include "utf8.h"
#include "ascii.h"

// 1 if the most recent bytes are a valid UTF-8 sequence (except base ASCII)
// 0 otherwise (ASCII, Extended ASCII, invalid UTF-8)
int is_utf8_multibyte = 0;

const char *utf8(char c){
	static char buf[UTF8_BUF_LEN];
	static unsigned int i = 0;

	/* UTF-8 quick-start (+ means at least one occurrence)
	 * 0b0xxxxxxx → single byte char
	 * 0b11+0xxxx → start of multi-byte char
	 * 0b10xxxxxx → cont. multi-byte char
	 */

	if(c & (1<<7)){
		if(c & (1<<6)){ // Start of multi-byte
			i = 0;
			if(c ^ 0x00){ // we must also have a 0 bit
				is_utf8_multibyte = 1;
			} else {
				is_utf8_multibyte = 0;
			}
		} else { // Continuation of multi-byte or an extended ASCII char
			if(!is_utf8_multibyte){
				i = 0;
			}
		}
	} else {
		i = 0;
		is_utf8_multibyte = 0;
	}

	// Prevent overflow with invalid input
	if(i > UTF8_CHAR_MAX_BYTES){
		i = 0;
		is_utf8_multibyte = 0;
	}
	
	buf[i] = c;
	if(is_utf8_multibyte){
		i++;
	}
	buf[i] = '\0';

	return buf;
}

const char *utf8_char_name(char c){
	if(c & (1<<7)){
		if(is_utf8_multibyte){
			if(c & (1<<6)){
				if(c ^ 0x00){
					return NAME_UTF8_START;
				} else {
					return ascii_char_name(c);
				}
			} else {
				return NAME_UTF8_CONTINUATION;
			}
		} else {
			return NAME_EXTENDED_ASCII;
		}
	} else {
		return ascii_char_name(c);
	}
}
