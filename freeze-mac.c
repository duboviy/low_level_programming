#include <mach/mach_init.h>
#include <mach/port.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    for (;;) {
        pid_t pid = fork();
        if (pid == 0) execv("/usr/bin/true", NULL); 
        mach_port_name_t task = MACH_PORT_NULL;
        task_for_pid(mach_task_self(), pid, &task);
        printf("Ran task_for_pid\n");
        int wait_status;
        wait(&wait_status);
    }
}
