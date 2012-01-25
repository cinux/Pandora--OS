#include "include/comfunc.h"
#include "inclue/def.h"
#include "include/stdio.h"
#include "include/global/isr.h"
#include "inclue/global/global.h"

VOID isr_handler (registers_t regs)
{
  printf ("Recieved interrupt: %i\n", regs.int_no);
}