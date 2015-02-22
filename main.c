#include <efi.h>
#include <efilib.h>

EFI_STATUS
EFIAPI
efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
   InitializeLib(ImageHandle, SystemTable);
   Print(L"Peter can't Cthulhu this.\n");
   Print(L"\nSTOP.\n\nHammertime.\n");

   return EFI_SUCCESS;
}
