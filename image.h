#ifndef image_h
#define image_h

#include "media.h"

class MediaManager;

class Image : public Media
{
    friend class MediaManager;

private:
    int width{};
    int height{};

protected:
    Image(const std::string &filePath, const std::string &name, const int width, const int height)
        : Media(filePath, name), width(width), height(height) {}
    Image() {}

public:
    std::string classname() const override { return "Image"; }
    virtual ~Image() { std::cout << "Destruction of image" << std::endl; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }
    void print(std::ostream &os) const override
    {
        Media::print(os);
        os << "\b, width:" << width << ", height:" << height << ">";
    };

    void play() const override
    {
        system(("gwenview " + getFilePath() + " &").data());
    }
    virtual void write(std::ostream &f) override
    {
        Media::write(f);
        f << width << '\n'
          << height << '\n';
    }
    virtual void read(std::istream &f) override
    {
        Media::read(f);
        f >> width >> height;
    }
};

#endif