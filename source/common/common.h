#ifndef   BASEFRAMEWORK_COMMON_H_
#define   BASEFRAMEWORK_COMMON_H_

#include <cstdio>
#include <cstdlib>
#include <cstring>

#if       _HAS_CSTDINT_
#include <cstdint>
#else  // _HAS_CSTDINT_
#include "compat_cstdint.h"
#endif // _HAS_CSTDINT_

#endif // BASEFRAMEWORK_COMMON_H_
