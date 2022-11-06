#ifndef _GIGACHAR_H_
#define _GIGACHAR_H_

typedef int gigachar;

#define GC_BOLD 0b0000000100000000
#define GC_DIM  0b0000001000000000
#define GC_ITALIC 0b0000010000000000
#define GC_UNDERLINE 0b0000100000000000
#define GC_BLINKING 0b0001000000000000
#define GC_INVERSE 0b0010000000000000
#define GC_HIDDEN 0b0100000000000000
#define GC_STRIKETROUGH 0b1000000000000000

#define GC_CHAR 0b0000000011111111

/*
ESC[1m	ESC[22m	set bold mode.
ESC[2m	ESC[22m	set dim/faint mode.
ESC[3m	ESC[23m	set italic mode.
ESC[4m	ESC[24m	set underline mode.
ESC[5m	ESC[25m	set blinking mode
ESC[7m	ESC[27m	set inverse/reverse mode
ESC[8m	ESC[28m	set hidden/invisible mode
ESC[9m	ESC[29m	set strikethrough mode.

*/

#endif