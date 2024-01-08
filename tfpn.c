#include <mach/mach.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
  kern_return_t kr;
  mach_port_t task = 0;
  if (argc != 2) {
    printf("Usage: %s <pid>\n", argv[0]);
    return 1;
  }
  int pid = atoi(argv[1]);

  kr = task_for_pid(mach_task_self(), pid, &task);
  if (kr != KERN_SUCCESS) {
    printf("tfp failed: %s\n", mach_error_string(kr));
    return kr;
  } else {
    printf("tfp %s: 0x%x\n", argv[1], task);
    return 0;
  }
}
