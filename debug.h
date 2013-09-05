#ifndef DEBUG_H
#define DEBUG_H

#ifndef NDEBUG
	#define DEBUG printf
#else
	#define DEBUG(...)
#endif

#endif /* DEBUG_H */
