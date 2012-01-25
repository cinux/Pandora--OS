// Author: Constantine Apostolou
// e-mail: conmarap@osarena.net

// Kernel entry point
#include "include/def.h"
#include "include/comfunc.h"
#include "include/kstdio.h"
#include "include/multiboot.h"
#include "include/stdio.h"

VOID _main ( struct multiboot *mboot_ptr, 
	     UINT32 initial_stack ) 
{
  kclear ();
  
  kprintf ("Boot successfull\n");
  int rand = 36;
  printf ("Number \"rand\" = %i.\n", rand);
  while (rand == 36) { }
}

// This module was the first to be used as the kernel's
// entry point.
//VOID _legacy_boot ( VOID* mbd, UINT magic )
//{
//  if ( magic != 0x2BADB002 )
//  {
//    // Something went wrong
//  }
//  
//  UCHAR *videomem = (UCHAR *) 0xb8000;
//  videomem[0] = 65;   // Character 'A'
//  videomem[1] = 0x07; // Light Grey [7] on Black [0]
//}

