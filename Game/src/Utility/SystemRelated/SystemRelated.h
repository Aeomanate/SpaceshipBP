#ifndef SPACESHIPBP_SYSTEMRELATED_H
#define SPACESHIPBP_SYSTEMRELATED_H

#include <filesystem>
namespace fs = std::filesystem;

class SystemRelated
{
public:
    static void ShowConsole();
    static void HideConsole();
    static bool CreateDirWhenAbsent(fs::path directory);
};


#endif //SPACESHIPBP_SYSTEMRELATED_H
