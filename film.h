#ifndef film_h
#define film_h

#include "video.h"

class MediaManager;

class Film : public Video
{
    friend class MediaManager;

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
    void writeChapters(std::ostream &f)
    {
        for (unsigned int i = 0; i < chapterCount; i++)
        {
            f << chapters[i] << " ";
        }
        f << '\n';
    }
    void readChapters(unsigned int parsedCount, std::istream &f)
    {
        unsigned int *parsedChapters = new unsigned int[parsedCount];
        for (unsigned int i = 0; i < parsedCount - 1; i++)
        {
            f >> parsedChapters[i];
        }
        setChapters(parsedCount, parsedChapters);
        delete[] parsedChapters;
    }

protected:
    Film() {}
    Film(const std::string &filePath, const std::string &name, const int duration, const unsigned int chapterCount, unsigned int const *chapters)
        : Video(filePath, name, duration) { setChapters(chapterCount, chapters); }

public:
    std::string classname() const override { return "Film"; }
    virtual ~Film()
    {
        delete[] chapters;
        std::cout << "Destruction of film" << std::endl;
    };

    unsigned int const *getChapters() const { return chapters; }

    unsigned int getChapterCount() const { return chapterCount; }

    void setChapters(unsigned int chapterCount, unsigned int const *chapters);

    void print(std::ostream &os) const override
    {
        Video::print(os);
        os << "\b, duration:" << getDuration() << ", chapters:" << getChapterString() << ">";
    }
    virtual void write(std::ostream &f) override
    {
        Video::write(f);
        f << chapterCount << '\n';
        writeChapters(f);
    }
    virtual void read(std::istream &f) override
    {
        unsigned int parsedChapterCount;
        Video::read(f);
        f >> parsedChapterCount;
        readChapters(parsedChapterCount, f);
    }
};

#endif