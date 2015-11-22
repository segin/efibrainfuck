#include "efibrainfuck.h"

EFI_SYSTEM_TABLE *sys_table;
EFI_BOOT_SERVICES *boot;
EFI_RUNTIME_SERVICES *runtime;

EFI_GUID gEfishellParametersProtocol = EFI_SHELL_PARAMETERS_PROTOCOL_GUID;

/**
 * AsciiStrLen - Finds the length of an ASCII string
 * @slen: The string
 *
 * Returns the length of an ASCII string, in characters. 
 */
UINTN AsciiStrLen (IN CHAR8 *slen)
{
  UINTN len;

  ASSERT (slen != NULL);

  for (len = 0; *slen; slen += 1, len += 1);
  return len;
}

static void
usage(void)
{
   Print(L"Usage: efibrainfuck code.bf [input.txt]\n");
   Print(L"If no input text provided, input will read zeros.\n");
}

// Message for Mr. Strand :) 
static CHAR8 defaultcode[] = "[-]>[-]<"
">++++++++[<++++++++>-]<++++++++."
">+++++[<+++++>-]<++++."
">+++[<+++>-]<--."
"."
"+++."
">+++++++++[<--------->-]<++."
">+++++++++[<+++++++++>-]<+++."
">+++[<--->-]<---."
"---."
">++++[<++++>-]<---."
">++++[<---->-]<+++."
">++++++++[<-------->-]<+++++++."
">+++[<--->-]<---."
">++++++[<++++++>-]<."
">+++++[<+++++>-]<++++."
">++++[<++++>-]<---."
">++[<-->-]<-."
"----."
">+++[<+++>-]<--."
">+++++++++[<--------->-]<++++++."
"-."
">++++++++[<++++++++>-]<-------."
">+++++[<+++++>-]<---."
">++[<++>-]<++."
"---."
">+++++++++[<--------->-]<-."
">+++++++++[<+++++++++>-]<++."
">++[<++>-]<++."
">++[<-->-]<--."
"+."
">++++[<---->-]<+."
">+++[<+++>-]<-."
">+++++++++[<--------->-]<++++."
">+++++++++[<+++++++++>-]<--------."
">+++[<+++>-]<+."
">+++++++++[<--------->-]<--."
">+++++++++[<+++++++++>-]<---."
"+."
">+++[<+++>-]<-."
">+++++++++[<--------->-]<------."
">++++++++[<++++++++>-]<++++++++."
">+++[<+++>-]<--."
"++++."
">++++[<---->-]<++."
"-."
">++++++++[<-------->-]<----."
">+++++[<+++++>-]<+."
">++++[<---->-]<-."
">+++[<--->-]<.";

EFI_STATUS
EFIAPI
efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
	struct bf_interp *interp; 
	EFI_STATUS status;
	EFI_SHELL_PARAMETERS_PROTOCOL ShellParameters;
	UINTN argc;
	CHAR16 **argv;
	InitializeLib(ImageHandle, SystemTable);
	sys_table = SystemTable;
	boot = sys_table->BootServices;
	runtime = sys_table->RuntimeServices;

	// Print startup banner
	Print(L"efibrainfuck git-20151121, firmware: %s %d.%02d\n", SystemTable->FirmwareVendor,
		SystemTable->FirmwareRevision >> 16, SystemTable->FirmwareRevision & ((1 << 16) - 1));

	// get argc/argv
	argc  = GetShellArgcArgv(ImageHandle, &argv);

	Print(L"argc = %d\n", argc);

	for (int c = 0;  c < argc;  c++ ) {
		Print(L"argv[%d] = <%s>\n", c, argv[c]);
	}


	// If not enough arguments then print usage and bail.
	if (argc < 2) {
		usage();
		return EFI_SUCCESS;
	}
	interp = bf_interp_init();
	bf_interp_run(interp, (char *) defaultcode);
	bf_interp_fini(interp);
	Print(L"\n");

	return EFI_SUCCESS;
	}
