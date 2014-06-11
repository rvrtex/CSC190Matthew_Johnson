#ifndef _DEBUGMEMORY_H
#define _DEBUGMEMORY_H

#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new (_CLIENT_BLOCK,__FILE__,__LINE__)
#define new DEBUG_NEW
#endif // _DEBUG


#endif // !_DEBUGMEMORY_H
