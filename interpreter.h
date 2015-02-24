/* interpreter.h: A Brainfuck interpreter engine. */

#ifndef __INTERPETER_H__
#define __INTERPETER_H__

/* Types */
struct bf_interp {
	UINTN pc;
	struct bf_tape *tape; 
};

/* Functions */
struct bf_interp *bf_interp_init(void);
void bf_interp_fini(struct bf_interp *this);


#endif /* __INTERPETER_H__ */