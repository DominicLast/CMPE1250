#include <hidef.h>
#include "derivative.h"
#include <stdio.h> 
#include <stdlib.h>
#include "misc.h"

unsigned int GetRandom (int iLow, int iHighEx){
    unsigned int value = rand() % (iHighEx-iLow) + iLow; 
    return value;
}

