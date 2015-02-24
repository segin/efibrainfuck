/* tape.h: A Brainfuck engine's tape's header. */

#ifndef __TAPE_H__
#define __TAPE_H__

#define TAPESIZE 0x10000

/* Types */
struct bf_tape { 
	UINTN position;
	char  tape[TAPESIZE];
};

/* Functions */
struct bf_tape *bf_tape_init(void);
void bf_tape_fini(struct bf_tape *this);
char bf_tape_get(struct bf_tape *this);
void bf_tape_set(struct bf_tape *this, char value);
void bf_tape_inc(struct bf_tape *this);
void bf_tape_dec(struct bf_tape *this);
void bf_tape_forward(struct bf_tape *this);
void bf_tape_reverse(struct bf_tape *this);

#endif /* __TAPE_H__ */