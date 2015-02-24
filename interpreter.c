/* interpreter.c: A Brainfuck interpreter engine. */

#include "efibrainfuck.h"

/**
 * bf_interp_init - construct an interpreter instance. 
 *
 * Return a pointer to an interpreter object. 
 */
struct bf_interp *bf_interp_init(void) {
	struct bf_interp *this = malloc(sizeof(struct bf_interp));
	this->tape = bf_tape_init();
	return this;
}

/**
 * bf_tape_fini - destruct an interpreter instance. 
 * @this: the interpreter instance to destroy
 *
 * Frees memory used by an interpreter instance. 
 */
void bf_interp_fini(struct bf_interp *this) {
	bf_tape_fini(this->tape);
	free(this);
}
