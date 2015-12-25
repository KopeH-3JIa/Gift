#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <vector>
#include "global.hpp"

using StringArray = std::vector<std::string>;

class Application
{
public:
    static Application& instance();
    ~Application();

    Application&        setArguments(const StringArray& args);
    StringArray         arguments() const;

    int run();

private:
    Application();
    Application(const Application&) = delete;
    void operator =(const Application&) = delete;
    Application(const Application&&) = delete;
    void operator =(const Application&&) = delete;
};

#endif // APPLICATION_H
