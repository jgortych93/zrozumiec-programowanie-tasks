Simple debugger that watches the chosen process and prints process events.

The program calls ptrace in TRACE_ME mode on child process and reads child process registry in parent process.


Notes:
Parent process awaits for child by calling waitpid. The program continues when signal is delivered and child process
has not __WIFEXITED (not exited) status.
rax is 64 bit registry word and eax is 32 bit registry word.
The last call is stored in orig_rax and orig_eax fields of user_regs_struct


Used registries (64 and 32 versions):
File descriptor: rdi and ebx
Text addresses: rsi and ecx
Text size: rdx and edx
