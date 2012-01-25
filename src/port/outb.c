// Author: Constantine Apostolou
// e-mail: conmarap@osarena.net

// Out port B function
#include "../include/comfunc.h"
#include "../include/def.h"

VOID outb (UINT16 port, UINT8 value)
{
    asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

