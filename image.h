#ifndef image_h
#define image_h

#include "media.h"

class Image : public Media
{
private:
    int width{};
    int height{};

public:
    Image(const std::string filePath, const std::string name, const int width, const int height) : Media(filePath, name), width(width), height(height) {}
    Image() {}
    virtual ~Image() {};
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }
    std::ostream &print(std::ostream &os) const override
    {
        os << "Image<name:" << getName() << ", path:" << getFilePath()
           << ", width:" << width << ", height:" << height << ">";
        return os;
    };

    void play() const
    {
        system(("gwenview " + getFilePath() + " &").data());
    }
};

#endif