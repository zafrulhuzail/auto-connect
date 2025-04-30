#include <unistd.h>
#include <sys/syscall.h>
int main() {
    syscall(SYS_reboot, 0xFEE1DEAD, 672274793, 0x1234567); // Magic numbers
    return 0;
}
