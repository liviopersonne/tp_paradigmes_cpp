//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "media.h"
#include "image.h"
#include "video.h"
#include "film.h"
#include "group.h"

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

    /* Etape 5  - 6 - 8*/

    unsigned int *chapters = new unsigned int[3];
    chapters[0] = 3;
    chapters[1] = 10;
    chapters[2] = 15;
    Image *cat = new Image("assets/cat.png", "cat", 225, 208);
    Video *snk = new Video("assets/snk.mp4", "snk", 34);
    Film *film = new Film("assets/snk.mp4", "snk", 34, 3, chapters);

    /* Etapes 5 & 6 */
    Media *medias[] = {cat, snk, film};
    for (int i = 0; i < 3; i++)
    {
        Media *media = medias[i];
        std::cout << *media << std::endl;
    }

    // C'est le polymorphisme qui permet cela
    // Il est nécessaire de créer une méthode abstraite dans Media pour permettre le polymorphisme
    // Ces objets sont de type Media*, il faut des pointeurs vers ces objets

    /* Etape 8 */
    Group *group = new Group("myGroup");
    std::cout << *group;
    group->push_back(cat);
    group->push_back(snk);
    group->push_back(film);
    std::cout << *group;

    // Free the memory
    delete cat;
    delete snk;
    delete film;

    return 0;
}
