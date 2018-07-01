#include "ascii.h"

const char *ascii_char_name(char c){
	if(c > 0x1F && c < 0x7F) return NAME_ASCII;
	switch(c){
		case 0x00: return "NUL";
		case 0x01: return "SOH";
		case 0x02: return "STX";
		case 0x03: return "ETX";
		case 0x04: return "EOT";
		case 0x05: return "ENQ";
		case 0x06: return "ACK";
		case 0x07: return "BEL";
		case 0x08: return "BS";
		case 0x09: return "HT";
		case 0x0A: return "LF";
		case 0x0B: return "VT";
		case 0x0C: return "FF";
		case 0x0D: return "CR";
		case 0x0E: return "SO";
		case 0x0F: return "SI";
		case 0x10: return "DLE";
		case 0x11: return "DC1";
		case 0x12: return "DC2";
		case 0x13: return "DC3";
		case 0x14: return "DC4";
		case 0x15: return "NAK";
		case 0x16: return "SYN";
		case 0x17: return "ETB";
		case 0x18: return "CAN";
		case 0x19: return "EM";
		case 0x1A: return "SUB";
		case 0x1B: return "ESC";
		case 0x1C: return "FS";
		case 0x1D: return "GS";
		case 0x1E: return "RS";
		case 0x1F: return "US";
		case 0x7F: return "DEL";
		default:   0;
	}
}
