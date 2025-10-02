#ifndef film_h
#define film_h

#include "video.h"

class Film : public Video
{
private:
    unsigned int chapterCount{};
    unsigned int *chapters{};
    std::string getChapterString() const
    {
        if (chapterCount == 0)
        {
            return "[]";
        }
        std::string s = "[";
        for (unsigned int i = 0; i < chapterCount; i++)
        {
            s += std::to_string(chapters[i]);
            s += ", ";
        }
        s += "\b\b]";
        return s;
    }

public:
    Film() {}
    Film(const std::string filePath, const std::string name, const int duration, const unsigned int chapterCount, unsigned int *const chapters) : Video(filePath, name, duration), chapterCount(chapterCount), chapters(chapters) {}
    virtual ~Film() { delete[] chapters; };
    unsigned int *getChapters() const { return chapters; }
    unsigned int getChapterCount() const { return chapterCount; }
    void setChapters(const unsigned int chapterCount, unsigned int *const chapters);
    Film *copy() const;
    std::ostream &print(std::ostream &os) const override
    {
        os << "Film<name:" << getName() << ", path:" << getFilePath()
           << ", duration:" << getDuration() << ", chapters:" << getChapterString() << ">";
        return os;
    };
};

#endif