#include "include/global/global.h"
#include "include/global/gdt.h"
#include "include/comfunc.h"

// Access the assembly driven functions through 
// this method.
extern VOID gdt_flush (UINT32);
extern VOID idt_flush (UINT32);

// Internal function prototypes.
static VOID init_gdt ();
static VOID init_idt();
static VOID gdt_set_gate (SINT32, UINT32, UINT32, UINT8, UINT8);
static VOID init_set_gate (UINT8, UINT32, UINT16, UINT8);

gdt_entry_t gdt_entries[5];
gdt_ptr_t   gdt_ptr;
idt_entry_t idt_entries[256];
idt_ptr_t   idt_ptr;

//
VOID init_dt ()
{
  init_gdt ();
  init_idt ();
}

// IDT init function
static VOID init_idt ()
{
    idt_ptr.limit = sizeof(idt_entry_t) * 256 -1;
    idt_ptr.base  = (UINT32)&idt_entries;

    memset(&idt_entries, 0, sizeof(idt_entry_t)*256);

    // Remap the irq table.
    outb(0x20, 0x11);
    outb(0xA0, 0x11);
    outb(0x21, 0x20);
    outb(0xA1, 0x28);
    outb(0x21, 0x04);
    outb(0xA1, 0x02);
    outb(0x21, 0x01);
    outb(0xA1, 0x01);
    outb(0x21, 0x0);
    outb(0xA1, 0x0);

    idt_set_gate( 0 , (UINT32)isr0  , 0x08, 0x8E);
    idt_set_gate( 1 , (UINT32)isr1  , 0x08, 0x8E);
    idt_set_gate( 2 , (UINT32)isr2  , 0x08, 0x8E);
    idt_set_gate( 3 , (UINT32)isr3  , 0x08, 0x8E);
    idt_set_gate( 4 , (UINT32)isr4  , 0x08, 0x8E);
    idt_set_gate( 5 , (UINT32)isr5  , 0x08, 0x8E);
    idt_set_gate( 6 , (UINT32)isr6  , 0x08, 0x8E);
    idt_set_gate( 7 , (UINT32)isr7  , 0x08, 0x8E);
    idt_set_gate( 8 , (UINT32)isr8  , 0x08, 0x8E);
    idt_set_gate( 9 , (UINT32)isr9  , 0x08, 0x8E);
    idt_set_gate(10 , (UINT32)isr10 , 0x08, 0x8E);
    idt_set_gate(11 , (UINT32)isr11 , 0x08, 0x8E);
    idt_set_gate(12 , (UINT32)isr12 , 0x08, 0x8E);
    idt_set_gate(13 , (UINT32)isr13 , 0x08, 0x8E);
    idt_set_gate(14 , (UINT32)isr14 , 0x08, 0x8E);
    idt_set_gate(15 , (UINT32)isr15 , 0x08, 0x8E);
    idt_set_gate(16 , (UINT32)isr16 , 0x08, 0x8E);
    idt_set_gate(17 , (UINT32)isr17 , 0x08, 0x8E);
    idt_set_gate(18 , (UINT32)isr18 , 0x08, 0x8E);
    idt_set_gate(19 , (UINT32)isr19 , 0x08, 0x8E);
    idt_set_gate(20 , (UINT32)isr20 , 0x08, 0x8E);
    idt_set_gate(21 , (UINT32)isr21 , 0x08, 0x8E);
    idt_set_gate(22 , (UINT32)isr22 , 0x08, 0x8E);
    idt_set_gate(23 , (UINT32)isr23 , 0x08, 0x8E);
    idt_set_gate(24 , (UINT32)isr24 , 0x08, 0x8E);
    idt_set_gate(25 , (UINT32)isr25 , 0x08, 0x8E);
    idt_set_gate(26 , (UINT32)isr26 , 0x08, 0x8E);
    idt_set_gate(27 , (UINT32)isr27 , 0x08, 0x8E);
    idt_set_gate(28 , (UINT32)isr28 , 0x08, 0x8E);
    idt_set_gate(29 , (UINT32)isr29 , 0x08, 0x8E);
    idt_set_gate(30 , (UINT32)isr30 , 0x08, 0x8E);
    idt_set_gate(31 , (UINT32)isr31 , 0x08, 0x8E);
    idt_set_gate(32 , (UINT32)irq0  , 0x08, 0x8E);
    idt_set_gate(33 , (UINT32)irq1  , 0x08, 0x8E);
    idt_set_gate(34 , (UINT32)irq2  , 0x08, 0x8E);
    idt_set_gate(35 , (UINT32)irq3  , 0x08, 0x8E);
    idt_set_gate(36 , (UINT32)irq4  , 0x08, 0x8E);
    idt_set_gate(37 , (UINT32)irq5  , 0x08, 0x8E);
    idt_set_gate(38 , (UINT32)irq6  , 0x08, 0x8E);
    idt_set_gate(39 , (UINT32)irq7  , 0x08, 0x8E);
    idt_set_gate(40 , (UINT32)irq8  , 0x08, 0x8E);
    idt_set_gate(41 , (UINT32)irq9  , 0x08, 0x8E);
    idt_set_gate(42 , (UINT32)irq10 , 0x08, 0x8E);
    idt_set_gate(43 , (UINT32)irq11 , 0x08, 0x8E);
    idt_set_gate(44 , (UINT32)irq12 , 0x08, 0x8E);
    idt_set_gate(45 , (UINT32)irq13 , 0x08, 0x8E);
    idt_set_gate(46 , (UINT32)irq14 , 0x08, 0x8E);
    idt_set_gate(47 , (UINT32)irq15 , 0x08, 0x8E);
    idt_set_gate(128, (UINT32)isr128, 0x08, 0x8E);

    idt_flush((UINT32)&idt_ptr);
}

// GDT init function
static VOID init_gdt ()
{
    gdt_ptr.limit = (sizeof(gdt_entry_t) * 6) - 1;
    gdt_ptr.base  = (UINT32)&gdt_entries;

    gdt_set_gate(0, 0, 0, 0, 0);                // Null segment
    gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment
    gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment
    gdt_set_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User mode code segment
    gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User mode data segment
    write_tss(5, 0x10, 0x0);

    gdt_flush((UINT32)&gdt_ptr);
}

// Set the gate for the IDT
static VOID idt_set_gate (UINT8 num, UINT32 base, 
			  UINT16 sel, UINT8 flags)
{
    idt_entries[num].base_lo = base & 0xFFFF;
    idt_entries[num].base_hi = (base >> 16) & 0xFFFF;

    idt_entries[num].sel     = sel;
    idt_entries[num].always0 = 0;
    idt_entries[num].flags   = flags  | 0x60;
}

// Set the gate for the GDT
static VOID gdt_set_gate (SINT32 num, UINT32 base, UINT32 limit, 
			  UINT8 access, UINT8 gran)
{
    gdt_entries[num].base_low    = (base & 0xFFFF);
    gdt_entries[num].base_middle = (base >> 16) & 0xFF;
    gdt_entries[num].base_high   = (base >> 24) & 0xFF;

    gdt_entries[num].limit_low   = (limit & 0xFFFF);
    gdt_entries[num].granularity = (limit >> 16) & 0x0F;
    
    gdt_entries[num].granularity |= gran & 0xF0;
    gdt_entries[num].access      = access;
}
