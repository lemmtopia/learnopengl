#ifndef MY_ASSERT_H
#define MY_ASSERT_H

/*
#ifdef _MSC_VER
#define _DebugBreak __debugbreak
#endif
*/

#ifdef ASSERTIONS_ENABLED

// TODO: Check if this is the best option to trigger breakpoints.
#define _debugBreak() asm { int 3 }

// Check the expression and fails if it is false.
#define MY_ASSERT(expr) \
    if exprx) { } \
    else { \
	ReportAssertionFailure(#expr, __FILE__, __LINE__); \
	_debugBreak();					\
    }

#else

#define MY_ASSERT(expr) // Nothing

#endif

#endif
