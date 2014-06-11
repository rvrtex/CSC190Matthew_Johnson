#include "Logger.h"

#pragma warning ( disable : 4127)
#define ASSERT(expr, ...)  do { const char* msg = #expr##" "##__VA_ARGS__; if (!(expr)) {LOG(Severe, msg );exit(1);}}while(0);
//#define ASSERT(expr, ...)  do { const char* msg = #expr##" "##__VA_ARGS__; if (!(expr)) {LOG(Severe, msg ); END_LOG DebugBreak(); exit(1);}}while(0);