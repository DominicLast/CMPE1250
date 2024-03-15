#include <hidef.h>
#include "derivative.h"
#include <stdio.h> 
#include <stdlib.h>
#include "misc.h"

int GetRandom (int iLow, int iHighEx){
    int value = rand() % (iHighEx-iLow) + iLow; 
    return value;
}

