#ifndef STUBS_SYS_PRCTL_H
#define STUBS_SYS_PRCTL_H

// Linux-only prctl() compatibility shim for macOS builds.
// The production code uses this to set thread names. On macOS we simply ignore it.

#include <cstdarg>
#include <pthread.h>

#ifndef PR_SET_NAME
#define PR_SET_NAME 15
#endif

inline int prctl(int option, ...)
{
    if (option == PR_SET_NAME) {
        va_list ap;
        va_start(ap, option);
        const char* name = va_arg(ap, const char*);
        va_end(ap);
        if (name == nullptr) {
            return -1;
        }
        return pthread_setname_np(name);
    }
    return 0;
}

#endif // STUBS_SYS_PRCTL_H
