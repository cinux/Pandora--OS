#include "../include/string.h"

/* * * * * * * * * * * * * * * * * * * * * * * * *
 *      Write leng copies of val into dest.      *
 * * * * * * * * * * * * * * * * * * * * * * * * */
void memset(UINT8 *dest, UINT8 val, UINT32 len)
{
    UINT8 *temp = (UINT8 *)dest;
    for ( ; len != 0; len--) *temp++ = val;
}

