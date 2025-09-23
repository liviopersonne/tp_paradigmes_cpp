//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "media.h"

int main(int argc, const char *argv[])
{
    Media *media1 = new Media("path/to/file/media1.mp3", "media1");
    Media *media2 = new Media("path/to/file/media2.mp4", "media2");

    std::cout << *media1 << std::endl;
    std::cout << media1->getName() << std::endl;
    media1->setName("newMedia1");
    std::cout << *media1 << std::endl;
    media2->setFilePath("new/path/to/file/media2.mp4");
    std::cout << *media2 << std::endl;
    return 0;
}
