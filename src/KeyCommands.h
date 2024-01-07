#include "iostream"
#ifndef GAMEMACROS_KEYCOMMANDS_H
#define GAMEMACROS_KEYCOMMANDS_H

class KeyCommands {
    private:
        unsigned int _mainKey = 0;
        unsigned int _pushKey[6] {0,0,0,0,0,0};
    public:
        KeyCommands();
        KeyCommands(unsigned int mainKey, const unsigned int pushKey[7]);
        unsigned int getMainKey() const;
        unsigned int* getPushKey();
};


#endif //GAMEMACROS_KEYCOMMANDS_H
