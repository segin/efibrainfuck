/* EFI Brainfuck */

#ifndef __EFIBRAINFUCK_H__
#define __EFIBRAINFUCK_H__

/* system includes */
#include <efi.h>
#include <efilib.h>

/* Global variables */
extern EFI_SYSTEM_TABLE *sys_table;
extern EFI_BOOT_SERVICES *boot;
extern EFI_RUNTIME_SERVICES *runtime;

/* Misc. global functions (see main.c) */
UINTN AsciiStrLen(IN CHAR8 *s1);

/* local includes */ 
#include "malloc.h"
#include "tape.h"
#include "interpreter.h"

#endif /* __EFIBRAINFUCK_H__ */ 
