; * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
; Codename Pegasus Operating System - Contains the process routine      *
; Copyright (C) 2011  Constantine M. Apostolou                          *
; Author: Constantine M. Apostolou - conmarap@osarena.net               *
;                                                                       *
; This program is free software: you can redistribute it and/or modify  *
; it under the terms of the GNU General Public License as published by  *
; the Free Software Foundation, either version 3 of the License, or     *
; (at your option) any later version.                                   *
;                                                                       *
; This program is distributed in the hope that it will be useful,       *
; but WITHOUT ANY WARRANTY; without even the implied warranty of        *
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
; GNU General Public License for more details.                          *
;                                                                       *
; You should have received a copy of the GNU General Public License     *
; along with this program.  If not, see <http://www.gnu.org/licenses/>. *
; * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

[GLOBAL read_eip]
read_eip:
    pop eax                     ; Get the return address
    jmp eax                     ; Return. Can't use RET because return
                                ; address popped off the stack. 

[GLOBAL copy_page_physical]
copy_page_physical:
    push ebx              ; According to __cdecl, we must preserve the contents of EBX.
    pushf                 ; push EFLAGS, so we can pop it and reenable interrupts
                          ; later, if they were enabled anyway.
    cli                   ; Disable interrupts, so we aren't interrupted.
                          ; Load these in BEFORE we disable paging!
    mov ebx, [esp+12]     ; Source address
    mov ecx, [esp+16]     ; Destination address
  
    mov edx, cr0          ; Get the control register...
    and edx, 0x7fffffff   ; and...
    mov cr0, edx          ; Disable paging.
  
    mov edx, 1024         ; 1024*4bytes = 4096 bytes
  
.loop:
    mov eax, [ebx]        ; Get the word at the source address
    mov [ecx], eax        ; Store it at the dest address
    add ebx, 4            ; Source address += sizeof(word)
    add ecx, 4            ; Dest address += sizeof(word)
    dec edx               ; One less word to do
    jnz .loop             
  
    mov edx, cr0          ; Get the control register again
    or  edx, 0x80000000   ; and...
    mov cr0, edx          ; Enable paging.
  
    popf                  ; Pop EFLAGS back.
    pop ebx               ; Get the original value of EBX back.
    ret
