#ifndef MY_ASSERT_H
#define MY_ASSERT_H

#define MESSAGE_SIZE 512

#ifdef ASSERTIONS_ENABLED

// Defining _debugBreak
#ifdef _MSC_VER
#define debug_break() __debugbreak()
#endif

// Check the expression and fails if it is false.
#define MY_ASSERT(expr) \
    if (expr) { }	\
    else { \
	report_assertion_failure(#expr, __FILE__, __LINE__); \
	debug_break();					\
    }

#else

#define MY_ASSERT(expr) // Nothing

#endif

#endif
