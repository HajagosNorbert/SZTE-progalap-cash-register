#ifndef DEBUG_TOOLS
#define DEBUG_TOOLS

#include <stdio.h>
//Norbert
void markCurrentLine(int line) {
    printf("[%d]\n", line);
}

void addMessageToCurrentLine(const char *file, int line, const char *message) {
    printf("%s at line [%d]: %s\n", file, line, message);
}

#ifdef DEBUG
#define mark markCurrentLine(__LINE__)
#define msg(m) addMessageToCurrentLine(__FILE__, __LINE__, m)
#else
#define mark
#define msg(m)
#endif //DEBUG

#endif //DEBUG_TOOLS