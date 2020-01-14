#ifndef OSNAME_H
#define OSNAME_H


#ifdef _WIN32
    #define os 1
#elif __linux__
    #define os 0
#elif __unix__
    #define os 2
#else
    #define os 3
#endif

#endif