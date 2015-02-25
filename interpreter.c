/* interpreter.c: A Brainfuck interpreter engine. */

#include "efibrainfuck.h"

/**
 * bf_interp_init - construct an interpreter instance. 
 *
 * Return a pointer to an interpreter object. 
 */
struct bf_interp *bf_interp_init(void) {
	struct bf_interp *this = malloc(sizeof(struct bf_interp));
	this->pc = 0;
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

/**
 * bf_tape_run - Runs a Brainfuck program
 * @this: the interpreter instance to run with
 * @code: ASCII string containing the full Brainfuck program text.
 *
 * It's a brainfuck interpreter. 
 */
void bf_interp_run(struct bf_interp *this, char *code) {
	CHAR16 *out;
	for(this->pc = 0; this->pc < AsciiStrLen((CHAR8 *) code); this->pc++) { 
		switch(code[this->pc]) {
			case '>':
				bf_tape_forward(this->tape);
				break;
			case '<':
				bf_tape_reverse(this->tape);
				break;
			case '+':
				bf_tape_inc(this->tape);
				break;
			case '-':
				bf_tape_dec(this->tape);
				break;
			case '.':
				out = malloc(4); 
				out[0] = bf_tape_get(this->tape);
				out[1] = 0;
				Print(out);
				free(out);
				break;
			case '[':
				if (bf_tape_get(this->tape) == 0) {
					int i = 1;
					while (i > 0) {
						++this->pc;
						switch(code[this->pc]) { 
							case '[':
								i++;
								break;
							case ']':
								i--;
								break;
						}
					}
				}
				break;
			case ']':
				if (bf_tape_get(this->tape) != 0) { 
					int i = 1;
					while (i > 0) { 
						--this->pc;
						switch(code[this->pc]) {
							case '[':
								i--;
								break;
							case ']':
								i++;
								break;
						}
					}
				}
				break;
		}
	}
}

