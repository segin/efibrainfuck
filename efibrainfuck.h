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

/* Portability macros */
#ifndef EFI_SHELL_PARAMETERS_PROTOCOL_GUID
#define EFI_SHELL_PARAMETERS_PROTOCOL_GUID \
	{ 0x752f3136, 0x4e16, 0x4fdc, \
	{ 0xa2, 0x2a, 0xe5, 0xf4, 0x68, 0x12, 0xf4, 0xca } }; 

	typedef struct _EFI_SHELL_PARAMETERS_PROTOCOL {
		 CHAR16 **Argv;
		 UINTN Argc;
		 EFI_FILE_HANDLE StdIn;
		 EFI_FILE_HANDLE StdOut;
		 EFI_FILE_HANDLE StdErr;
	} EFI_SHELL_PARAMETERS_PROTOCOL; 
#endif /* EFI_SHELL_PARAMETERS_PROTOCOL_GUID */

#endif /* __EFIBRAINFUCK_H__ */ 
