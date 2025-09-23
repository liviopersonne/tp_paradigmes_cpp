//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "media.h"
#include "image.h"
#include "video.h"

int main(int argc, const char *argv[])
{
    /* Etapes 1-3 */
    // Media *media1 = new Media("path/to/file/media1.mp3", "media1");
    // Media *media2 = new Media("path/to/file/media2.mp4", "media2");

    // std::cout << *media1 << std::endl;
    // std::cout << media1->getName() << std::endl;
    // media1->setName("newMedia1");
    // std::cout << *media1 << std::endl;
    // media2->setFilePath("new/path/to/file/media2.mp4");
    // std::cout << *media2 << std::endl;

    /* Etape 4 */
    // Image *cat = new Image("assets/cat.png", "cat", 225, 208);
    // Video *snk = new Video("assets/snk.mp4", "snk", 34);
    // std::cout << *cat << std::endl;
    // std::cout << *snk << std::endl;
    // cat->play();
    // snk->play();

    /* Etape 5 */
    Image *cat = new Image("assets/cat.png", "cat", 225, 208);
    Video *snk = new Video("assets/snk.mp4", "snk", 34);
    Media **medias = new Media *[2];
    medias[0] = cat;
    medias[1] = snk;

    for (int i = 0; i < 2; i++)
    {
        Media *media = medias[i];
        std::cout << *media << std::endl;
    }

    // C'est le polymorphisme qui permet cela
    // Il est nécessaire de créer une méthode abstraite dans Media pour permettre le polymorphisme
    // Ces objets sont de type Media*, il faut des pointeurs vers ces objets

    // Free the memory
    for (int i = 0; i < 2; i++)
    {
        delete medias[i];
    }
    delete[] medias;

    return 0;
}
