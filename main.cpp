//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include <memory>
#include "media.h"
#include "image.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "media_manager.h"

void create_groups(std::shared_ptr<MediaManager> manager)
{
    MediaPtr cat = manager->createImage("assets/cat.png", "cat", 225, 208);
    MediaPtr snk = manager->createVideo("assets/snk.mp4", "snk", 34);
    unsigned int *chapters = new unsigned int[3]{3, 10, 15};
    MediaPtr film = manager->createFilm("assets/snk.mp4", "snkFilm", 34, 3, chapters);
    GroupPtr group1 = manager->createGroup("group1");
    GroupPtr group2 = manager->createGroup("group2");
    group1->push_back(cat);
    group2->push_back(snk);
    group2->push_back(cat);
    group2->push_back(film);
}

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

    /*
    unsigned int *chapters = new unsigned int[3];
    chapters[0] = 3;
    chapters[1] = 10;
    chapters[2] = 15;
    Image *cat = new Image("assets/cat.png", "cat", 225, 208);
    Video *snk = new Video("assets/snk.mp4", "snk", 34);
    Film *film = new Film("assets/snk.mp4", "snkFilm", 34, 3, chapters);

    Media *medias[] = {cat, snk, film};
    for (int i = 0; i < 3; i++)
    {
        Media *media = medias[i];
        std::cout << *media << std::endl;
    }

    // C'est le polymorphisme qui permet cela
    // Il est nécessaire de créer une méthode abstraite dans Media pour permettre le polymorphisme
    // Ces objets sont de type Media*, il faut des pointeurs vers ces objets

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
    */

    /* Etape 9 */
    /*
    std::shared_ptr<Image> cat(new Image("assets/cat.png", "cat", 225, 208));
    std::shared_ptr<Video> snk(new Video("assets/snk.mp4", "snk", 34));
    unsigned int *chapters = new unsigned int[3]{3, 10, 15};
    std::shared_ptr<Film> film(new Film("assets/snk.mp4", "snkFilm", 34, 3, chapters));
    Group *group = new Group("myGroup");
    group->push_back(cat);
    group->push_back(snk);
    group->push_back(film);
    std::cout << *group << std::endl;
    group->pop_back();
    std::cout << *group << std::endl;
    group->pop_back();
    std::cout << *group << std::endl;
    group->pop_back();
    std::cout << *group << std::endl;
    */

    /* Etape 10 */
    // On rend les constructeurs privés pour éviter l'instanciation avec "new"
    // En fait on va plutôt les rendre protected pour que film puisse utiliser le constructeur de video

    std::shared_ptr<MediaManager> manager(new MediaManager());
    manager->createImage("assets/cat.png", "cat", 225, 208);
    manager->createVideo("assets/snk.mp4", "snk", 34);
    manager->searchMedia("cat");
    manager->searchMedia("aaa");
    // manager->playMedia("cat");
    // manager->playMedia("snk");

    // Test de suppression de media
    create_groups(manager);
    /* la creation de groupes est faite dans une fonction à part pour éviter de garder une référence
        aux pointeurs, ce qui bloquerait la destruction des éléments lors de leur suppression.*/
    manager->searchGroup("group1");
    manager->searchGroup("group2");
    manager->searchMedia("cat");
    manager->deleteMedia("bbb");
    manager->deleteMedia("cat");
    manager->searchGroup("group1");
    manager->searchGroup("group2");
    manager->searchMedia("cat");

    // Test de suppression de groupe
    manager->deleteGroup("aaa");
    manager->deleteGroup("group2");
    manager->searchGroup("group1");
    manager->searchGroup("group2");

    return 0;
}