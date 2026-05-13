#ifndef DISABLE_ROOTLESS_COMPAT_WARNING
#pragma GCC diagnostic	push
#pragma GCC diagnostic	warning "-Wpragmas"
#pragma GCC warning		"You're building roothide package with leagy rootless.h, upgrade to the roothide APIs for full compatibility with rootful/rootless/roothide : https://github.com/roothide/Developer"
#pragma GCC diagnostic	pop
#endif

#define __DO_PRAGMA(x)				_Pragma(#x)
#define __UNSUPPORTED_MACRO			__DO_PRAGMA(GCC error "Please upgrade to the roothide APIs for full compatibility with rootful/rootless/roothide : https://github.com/roothide/Developer")
#define __INCOMPATIBLE_API(x)		__DO_PRAGMA(GCC error "The " #x " API is not available through rootless.h, please switch to roothide.h for full compatibility with rootful/rootless/roothide : https://github.com/roothide/Developer")

#if !__has_attribute(overloadable)
#error "roothide.h requires overloading support"
#endif

#include <roothide.h>

#define ROOT_PATH(cPath)				jbroot(path)
#define ROOT_PATH_NS(path)				jbroot(path)

#define ROOT_PATH_VAR(path)				jbroot(path)
#define ROOT_PATH_NS_VAR(path)			jbroot(path)

#define JBROOT_PATH(path)				jbroot(path)
#define JBROOT_PATH_CSTRING(path)		jbroot(path)
#define JBROOT_PATH_NSSTRING(path)		jbroot(path)

#define ROOTFS_PATH(path) 				({__UNSUPPORTED_MACRO; (const char *)0; })
#define ROOTFS_PATH_CSTRING(path) 		({__UNSUPPORTED_MACRO; (const char *)0; })
#define ROOTFS_PATH_NSSTRING(path) 		({__UNSUPPORTED_MACRO; (const char *)0; })

#define jbrand()						({__INCOMPATIBLE_API(jbrand); 0; })
#define rootfs(path)					({__INCOMPATIBLE_API(rootfs); (const char *)0; })
