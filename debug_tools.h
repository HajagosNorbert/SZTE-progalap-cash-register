#ifndef DEBUG_TOOLS
#define DEBUG_TOOLS

#include <stdio.h>
//Norbert
void markCurrentLine(int line) {
    printf("[%d]\n", line);
}

void addMessageToCurrentLine(int line, const char *message) {
    printf("[%d] %s\n", line, message);
}

#ifdef DEBUG
#define mark markCurrentLine(__LINE__)
#define msg(m) addMessageToCurrentLine(__LINE__, m)
#else
#define mark
#define msg(m)
#endif //DEBUG

#endif //DEBUG_TOOLS