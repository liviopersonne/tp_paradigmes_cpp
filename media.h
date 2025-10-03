#ifndef media_h
#define media_h

#include <string>
#include <iostream>
#include <memory>

class MediaManager;

class Media
{
    friend class MediaManager;

private:
    std::string filePath{};
    std::string name{};

protected:
    Media(const std::string filePath, const std::string name) : filePath(filePath), name(name) {}
    Media() {}

public:
    virtual ~Media() {}
    std::string getFilePath() const { return filePath; }
    std::string getName() const { return name; }
    void setFilePath(const std::string p) { filePath = p; }
    void setName(const std::string n) { name = n; }

    // Operator redefinition to print an instance
    friend std::ostream &operator<<(std::ostream &os, const Media &media)
    {
        return media.print(os);
    };
    virtual std::ostream &print(std::ostream &os) const
    {
        os << "Media<name:" << this->getName() << ", path:" << this->getFilePath() << ">";
        return os;
    };
    virtual void play() const = 0;
};

#endif