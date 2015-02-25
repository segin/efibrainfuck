/* tape.c: A Brainfuck engine's tape. */

#include "efibrainfuck.h"

/**
 * bf_tape_init - construct a tape object. 
 *
 * Return a pointer to a tape object. Zeros local memory.
 */
struct bf_tape *bf_tape_init(void) {
	struct bf_tape *this = malloc(sizeof(struct bf_tape));
	int i;
	this->position = 0;
	for(i = 0; i < TAPESIZE; i++) 
		this->tape[i] = 0;
	return this;
}

/**
 * bf_tape_fini - destruct a tape object
 * @this: the tape to destroy
 *
 * Frees memory used by a tape. 
 */
void bf_tape_fini(struct bf_tape *this) {
	free(this);
}

/**
 * bf_tape_get - Return the value at the current tape index.
 * @this: Pointer to tape object
 *
 * Returns a 'char' containing the value at the current tape index. 
 */
char bf_tape_get(struct bf_tape *this) {
	return this->tape[this->position];
}

/**
 * bf_tape_set - Change the value at the current tape index.
 * @this: Pointer to tape object
 * @value: New value
 *
 * Sets the value stored at the current tape index to @value. 
 */
void bf_tape_set(struct bf_tape *this, char value) {
	this->tape[this->position] = value;
}

/**
 * bf_tape_inc - Increments the value at the current tape index.
 * @this: Pointer to tape object
 *
 * Increments the value stored at the current tape index.
 */
void bf_tape_inc(struct bf_tape *this) { 
	this->tape[this->position]++;
}

/**
 * bf_tape_dec - Decrements the value at the current tape index.
 * @this: Pointer to tape object
 *
 * Decrements the value stored at the current tape index. 
 */
void bf_tape_dec(struct bf_tape *this) { 
	this->tape[this->position]--;
}

/**
 * bf_tape_forward - Advances the tape forward
 * @this: Pointer to tape object
 *
 * Increments the tape index. If one attempts to seek past the end of 
 * the tape, the index will be reset to the beginning.
 */
void bf_tape_forward(struct bf_tape *this) {
	if (this->position >= (TAPESIZE - 1)) {
		this->position = 0;
	} else {
		this->position++;
	}
}
 
/**
 * bf_tape_reverse - Retreats the tape backwards
 * @this: Pointer to tape object
 *
 * Decrements the tape index. If one attempts to seek past the start of 
 * the tape, the index will be reset to the end.
 */
void bf_tape_reverse(struct bf_tape *this) {
        if (this->position <= 0) {
		this->position = (TAPESIZE - 1);
        } else {
		this->position--;
        }
}