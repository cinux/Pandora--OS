// Author: Constantine Apostolou
// e-mail: conmarap@osarena.net

// In port W function
#include "../include/comfunc.h"
#include "../include/def.h"

UINT16 inpw (UINT16 port)
{
    UINT16 ret;
    asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}
