#include "film.h"

void Film::setChapters(const unsigned int newChapterCount, unsigned int const *newChapters)
{
    for (unsigned int i = 0; i < newChapterCount - 1; i++)
    {
        if (newChapters[i] > newChapters[i + 1])
        {
            // Les chapitres ne sont pas dans l'ordre croissant
            std::cout << "Warning: Les chapitres ne sont pas dans l'ordre croissant" << std::endl;
            return;
        }
    }
    if (newChapters[newChapterCount] > getDuration())
    {
        // Les chapitres dépassent la fin du film
        std::cout << "Warning: Les chapitres dépassent la fin du film" << std::endl;
        return;
    }
    delete[] chapters;
    chapters = new unsigned int[newChapterCount];
    for (unsigned int i = 0; i < newChapterCount - 1; i++)
    {
        chapters[i] = newChapters[i];
    }
    chapterCount = newChapterCount;
}
