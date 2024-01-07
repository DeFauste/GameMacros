#include "KeyCommands.h"

KeyCommands::KeyCommands() = default;

KeyCommands::KeyCommands(unsigned int mainKey, const unsigned int pushKey[6]) {
    _mainKey = mainKey;
    for (unsigned int i = 0; i < 6; i++) {
        _pushKey[i] = pushKey[i];
    }
}

unsigned int *KeyCommands::getPushKey() {
    unsigned int* p = _pushKey;
    return p;
}

unsigned int KeyCommands::getMainKey() const {
    return _mainKey;
}
