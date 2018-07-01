#ifndef _UTF8_H_
#define _UTF8_H_


#define NAME_UTF8_START "u-start"
#define NAME_UTF8_CONTINUATION "u-cont"

// UTF-8 chars are <= 6 bytes. https://en.wikipedia.org/wiki/UTF-8
#define UTF8_CHAR_MAX_BYTES 6
#define UTF8_BUF_LEN (UTF8_CHAR_MAX_BYTES + 1)

// in: char, out: string describing the byte in a UTF-8 context.
const char *utf8_char_name(char);

// in: byte, out: string of bytes comprising a UTF-8 character.
const char *utf8(char);


#endif
