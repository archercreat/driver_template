#include <ntddk.h>

extern "C" int hello_asm();

void unload( PDRIVER_OBJECT drv )
{
    UNREFERENCED_PARAMETER( drv );
}

extern "C"
NTSTATUS DriverEntry( PDRIVER_OBJECT drv, PUNICODE_STRING reg )
{
    UNREFERENCED_PARAMETER( reg );
    // Make driver unloadable.
    //
    drv->DriverUnload = unload;

    hello_asm();

    return STATUS_SUCCESS;
}
