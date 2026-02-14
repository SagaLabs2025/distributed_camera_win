#ifndef STD_COMPAT_H
#define STD_COMPAT_H

// Standard C++ headers that must be included early to avoid conflicts
#include <map>
#include <vector>
#include <string>
#include <memory>
#include <functional>
#include <algorithm>
#include <cinttypes>  // For PRIu64, PRId64, etc.
#include <thread>     // For std::thread

// Define EOK if not already defined (success error code)
#ifndef EOK
#define EOK 0
#endif

#endif // STD_COMPAT_H
