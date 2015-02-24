/* tape.h: A Brainfuck engine's tape's header. */

#ifndef __TAPE_H__
#define __TAPE_H__

#define TAPESIZE 0x10000

struct bf_tape { 
	UINTN position;
	char  tape[TAPESIZE];
};

#endif /* __TAPE_H__ */