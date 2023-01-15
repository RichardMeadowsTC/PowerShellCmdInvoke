// ErrorSimulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "CParser.h"

int main(int argc, char *argv[])
{
    CParser parsed(argc, argv);
    parsed.Parse();
    fprintf(parsed.GetStream(), "Hello World!\n");
    return parsed.GetReturn();
}