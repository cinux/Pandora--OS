// Author: Constantine Apostolou
// e-mail: conmarap@osarena.net

// In port B function
#include "../include/comfunc.h"
#include "../include/def.h"

UINT8  inpb (UINT16 port)
{
    UINT8 ret;
    asm volatile ("inb %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}
