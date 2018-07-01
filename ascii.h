#ifndef _ASCII_H_
#define _ASCII_H_


#define NAME_ASCII "ASCII"
#define NAME_EXTENDED_ASCII "x-ASCII"

// in: byte
// out: string describing it if it's non-printable ASCII
//      or 0 pointer of the byte is either printable ASCII or not ASCII
const char *ascii_char_name(char c);


#endif
