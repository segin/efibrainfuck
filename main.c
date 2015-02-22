#include <efi.h>
#include <efilib.h>

static void
usage(void)
{
   Print(L"Usage: efibrainfuck code.bf\n");
}

EFI_STATUS
EFIAPI
efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
   EFI_STATUS status;
   UINTN argc;
   CHAR16 **argv;
   InitializeLib(ImageHandle, SystemTable);
   status = get_args(ImageHandle, &argc, &argv);
   if (EFI_ERROR(status)) { 
     Print(L"ERROR: Parsing command line arguments: %d\n", status); 
     return status; 
   }
   
   
   
   return EFI_SUCCESS;
}
