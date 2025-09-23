//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "media.h"

int main(int argc, const char *argv[])
{
    Media media1 = Media("path/to/file/media1.mp3", "media1");

    std::cout << media1 << std::endl;
    return 0;
}
