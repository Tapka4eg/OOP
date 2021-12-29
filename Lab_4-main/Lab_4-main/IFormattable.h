#pragma once

#include "Deck.h"
#include <string>

using namespace std;

class IFormattable 
{
public:
    virtual string format() = 0;
    virtual void prettyPrint(const Deck& object) = 0;
};

