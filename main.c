#include "efibrainfuck.h"

EFI_SYSTEM_TABLE *sys_table;
EFI_BOOT_SERVICES *boot;
EFI_RUNTIME_SERVICES *runtime;

static void
usage(void)
{
   Print(L"Usage: efibrainfuck code.bf [input.txt]\n");
   Print(L"If no input text provided, input will read zeros.\n");
}

EFI_STATUS
EFIAPI
efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
   EFI_STATUS status;
   UINTN argc;
   CHAR16 **argv;
   InitializeLib(ImageHandle, SystemTable);
   sys_table = SystemTable;
   boot = sys_table->BootServices;
   runtime = sys_table->RuntimeServices;
   status = get_args(ImageHandle, &argc, &argv);
   if (EFI_ERROR(status)) { 
     Print(L"ERROR: Parsing command line arguments: %d\n", status); 
     return status; 
   }
   if (argc < 2) {
     usage();
     return EFI_SUCCESS;
   }
   
   
   return EFI_SUCCESS;
}
