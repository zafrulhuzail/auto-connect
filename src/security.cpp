#include <iostream>
#include <seccomp.h>
#include <unistd.h>

void setup_security() {
    std::cout << "🛡️ Initializing SECCOMP...\n";
    scmp_filter_ctx ctx = seccomp_init(SCMP_ACT_KILL); // Default: KILL process
    
    // MUST ADD ARCHITECTURE
    seccomp_arch_add(ctx, SCMP_ARCH_X86_64);

    // EXPLICITLY ALLOW ONLY ESSENTIAL SYSCALLS
    const int allowed[] = {
        // Basic I/O
        SCMP_SYS(read),
        SCMP_SYS(write),
        SCMP_SYS(open),
        SCMP_SYS(close),
        
        // Networking
        SCMP_SYS(socket),
        SCMP_SYS(ioctl),  // Used for network interface checks
        SCMP_SYS(setsockopt),
        SCMP_SYS(bind),
	SCMP_SYS(getsockopt),  // Used by libiptc
        SCMP_SYS(setsockopt),
    	SCMP_SYS(getsockname),
        
        // System
        SCMP_SYS(exit),
        SCMP_SYS(clock_nanosleep),
        SCMP_SYS(getpid),
        
        // Memory
        SCMP_SYS(brk),
        SCMP_SYS(mmap),
        
        // Required for system() calls if used elsewhere
        SCMP_SYS(fork),
        SCMP_SYS(execve),
        SCMP_SYS(wait4),
	SCMP_SYS(clone),
    	SCMP_SYS(chdir),
    	SCMP_SYS(stat)
    };
    for (int syscall : allowed) {
        seccomp_rule_add(ctx, SCMP_ACT_ALLOW, syscall, 0);
    }

    // BLOCK REBOOT WITH MULTIPLE METHODS
    seccomp_rule_add(ctx, SCMP_ACT_KILL, SCMP_SYS(reboot), 0);
    seccomp_rule_add(ctx, SCMP_ACT_KILL, SCMP_SYS(kexec_load), 0);
    
    if (seccomp_load(ctx) != 0) {
        std::cerr << "💥 SECCOMP LOAD FAILED!\n";
        exit(1);
    }
    std::cout << "🔒 NUCLEAR LOCKDOWN ACTIVATED\n";
}
