#ifndef REGISTRY_READ_INSTRUCTIONS_HPP
#define REGISTRY_READ_INSTRUCTIONS_HPP

#if __WORDSIZE == 64
    #define LASTCALL(reg) reg.orig_rax
    #define FD(reg) reg.rdi
    #define TEXT_ADDRESS(reg) reg.rsi
    #define COUNT(reg) reg.rdx
#else
    #define LASTCALL(reg) reg.orig_eax
    #define FD(reg) reg.ebx
    #define TEXT_ADDRESS(reg) reg.ecx
    #define COUNT(reg) reg.edx
#endif

#endif // REGISTRY_READ_INSTRUCTIONS_HPP
