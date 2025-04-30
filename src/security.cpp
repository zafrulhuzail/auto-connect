#include <iostream>
#include <seccomp.h>
#include <unistd.h>

void setup_security() {
    std::cout << "Initializing security...\n";
    scmp_filter_ctx ctx = seccomp_init(SCMP_ACT_ALLOW);
   
    seccomp_arch_add(ctx, SCMP_ARCH_X86_64);
    // Restrict to only needed syscalls
    seccomp_rule_add(ctx, SCMP_ACT_ERRNO(EPERM), SCMP_SYS(reboot), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ERRNO(EPERM), SCMP_SYS(mount), 0);
    
    seccomp_load(ctx);
    std::cout << "Security restrictions applied\n";
}
