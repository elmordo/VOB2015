#ifndef UTILS_H
#define UTILS_H


#ifdef _WIN32
#define EOL "\r\n"
#elif defined(__APPLE__)
#define EOL "\n"
#else
#define EOL "\n"
#endif

#endif