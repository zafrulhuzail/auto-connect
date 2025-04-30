#include <unistd.h>
#include <linux/reboot.h>
#include <sys/reboot.h>
int main() { return reboot(LINUX_REBOOT_CMD_RESTART); }
