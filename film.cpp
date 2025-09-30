#include "film.h"

void Film::setChapters(const unsigned int newChapterCount, unsigned int *const newChapters)
{
    for (int i = 0; i < newChapterCount - 1; i++)
    {
        if (newChapters[i] > newChapters[i + 1])
        {
            // Les chapitres ne sont pas dans l'ordre croissant
            return;
        }
    }
    if (newChapters[newChapterCount] > getDuration())
    {
        // Les chapitres dépassent la fin du film
        return;
    }
    delete[] chapters;
    chapters = newChapters;
    chapterCount = newChapterCount;
}