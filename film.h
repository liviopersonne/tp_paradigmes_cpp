#ifndef film_h
#define film_h

#include "video.h";

class Film : public Video
{
private:
    unsigned int chapterCount{};
    unsigned int *chapters{};

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
           << ", duration:" << getDuration() << ", chapters:" << chapters << ">";
        return os;
    };
};

#endif