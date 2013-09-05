#ifndef DEBUG_H
#define DEBUG_H

#ifdef DEBUGMEMORY
	#define DEBUGMEM printf
#else
	#define DEBUGMEM(...)
#endif


#endif /* DEBUG_H */
