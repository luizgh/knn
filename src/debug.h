#ifndef DEBUG_H
#define DEBUG_H

#ifdef DEBUG_MEMORY
	#define DEBUGMEM printf
#else
	#define DEBUGMEM(...)
#endif

#ifdef DEBUG_KNN
	#define DEBUGKNN printf
#else
	#define DEBUGKNN(...)
#endif

#endif /* DEBUG_H */
