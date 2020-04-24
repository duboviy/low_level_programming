#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// usage: ./setuid 2345 
// will set your UID to 2345
// Must be run as root.
int main(int argc, const char** argv) {
    int uid = atoi(argv[1]);
    int result = setuid(uid);
    if (result != 0) {
        perror("Failed to setuid");
        return -1;
    }
    char *newargv[] = { NULL };
    char *newenviron[] = { NULL };
    execve("/bin/bash", newargv, newenviron);
}
