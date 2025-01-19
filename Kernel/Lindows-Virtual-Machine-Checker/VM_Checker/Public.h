/*++

Module Name:

    public.h

Abstract:

    This module contains the common declarations shared by driver
    and user applications.

Environment:

    user and kernel

--*/

//
// Define an Interface Guid so that apps can find the device and talk to it.
//

DEFINE_GUID (GUID_DEVINTERFACE_VMChecker,
    0x0858cef1,0x4191,0x423d,0xa2,0x3e,0x6f,0x3a,0x94,0xb3,0xc4,0x5d);
// {0858cef1-4191-423d-a23e-6f3a94b3c45d}
