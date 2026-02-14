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

// Camera framework types (需要在C++代码中使用)
#include "camera_framework_types.h"

// Define EOK if not already defined (success error code)
#ifndef EOK
#define EOK 0
#endif

#endif // STD_COMPAT_H
