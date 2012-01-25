#ifndef GDT_H
#define GDT_H

// Include def.h
#include "global.h"

// Descriptor table initialization function that is 
// publicly accessible.
VOID init_dt ();
VOID set_kernel_stack (UINT32 stack);

// This structure contains the value of one GDT entry.
// We use the attribute "packed" to tell GCC not to 
// change any of the alignment in the structure.
struct gdt_entry
{
  UINT16 limit_low;	// The lower 16 bits of the limit.
  UINT16 base_low;	// The lower 16 bits of the base.
  UINT8  base_middle;	// The next 8 bits of the base.
  UINT8  access;	// Access flags: Determine what ring this segment can be used in
  UINT8  granularity;	// 
  UINT8  base_high;	// The final 8 bits of the base.
} 
__attribute__ ((packed));

typedef struct gdt_entry gdt_entry_t; // Redefine it.

// To tell the processor where to find the GDT entry
// we'll have to give it the address of a special 
// pointer structure. Same thing as above for the 
// "packed" attribute definition. See bellow:
struct gdt_ptr
{
  UINT16 limit;		// The upper 16 bits of all limits.
  UINT32 base;		// The address of the first gt_entry_t structure.
} 
__attribute__ ((packed));

typedef struct gdt_ptr gdt_ptr_t;     // Redefine it.

// The structure describing an interrupt gate. 
struct idt_entry_struct
{
    UINT16 base_lo;             // The lower 16 bits of the address to jump to when this interrupt fires.
    UINT16 sel;                 // Kernel segment selector.
    UINT8  always0;             // This must always be zero.
    UINT8  flags;               // More flags. See documentation.
    UINT16 base_hi;             // The upper 16 bits of the address to jump to.
} __attribute__((packed));

typedef struct idt_entry_struct idt_entry_t;

// A struct describing a pointer to an array of 
/* * * * * * * * * * * * * * * * * * * * * * * * *
 *     Define the ISR handlers and access the    *
 *       addresses of our ASM ISR handlers.      *
 * * * * * * * * * * * * * * * * * * * * * * * * */
// an array of interrupt handlers.      
// Writen in a format for giving to 'lidt'   
struct idt_ptr_struct
{
    UINT16 limit;
    UINT32 base;                // The address of the first element in our idt_entry_t array.
} __attribute__((packed));

typedef struct idt_ptr_struct idt_ptr_t;

struct tss_entry_struct
{
    u32int prev_tss;   // The previous TSS - if we used hardware task switching this would form a linked list.
    u32int esp0;       // The stack pointer to load when we change to kernel mode.
    u32int ss0;        // The stack segment to load when we change to kernel mode.
    u32int esp1;       // Unused...
    u32int ss1;
    u32int esp2;  
    u32int ss2;   
    u32int cr3;   
    u32int eip;   
    u32int eflags;
    u32int eax;
    u32int ecx;
    u32int edx;
    u32int ebx;
    u32int esp;
    u32int ebp;
    u32int esi;
    u32int edi;
    u32int es;         // The value to load into ES when we change to kernel mode.
    u32int cs;         // The value to load into CS when we change to kernel mode.
    u32int ss;         // The value to load into SS when we change to kernel mode.
    u32int ds;         // The value to load into DS when we change to kernel mode.
    u32int fs;         // The value to load into FS when we change to kernel mode.
    u32int gs;         // The value to load into GS when we change to kernel mode.
    u32int ldt;        // Unused...
    u16int trap;
    u16int iomap_base;

} __attribute__((packed));

typedef struct tss_entry_struct tss_entry_t;

// Define the ISR handlers and access the addresses
// of our assembly ISR handler.
extern void isr0 ();
extern void isr1 ();
extern void isr2 ();
extern void isr3 ();
extern void isr4 ();
extern void isr5 ();
extern void isr6 ();
extern void isr7 ();
extern void isr8 ();
extern void isr9 ();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();
extern void irq0 ();
extern void irq1 ();
extern void irq2 ();
extern void irq3 ();
extern void irq4 ();
extern void irq5 ();
extern void irq6 ();
extern void irq7 ();
extern void irq8 ();
extern void irq9 ();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();
extern void isr128();

#endif