#include "Logger.h"

#include <fstream>
#include <filesystem>
#include <iostream>

#include "Core/Application/Application.h"

namespace fs = std::filesystem;

void Logger::Log(const std::string& message)
{
    fs::path logFolder(getConfig().application.logFolder);
    std::string logFileName = "ProgramOutput.log";

    std::ofstream log;
    log.open(logFolder / logFileName, std::ios_base::app | std::ios_base::out);

    if(!log.is_open())
    {
        Application::ShowConsole();
        std::cerr << getLoc().configNotFound << std::endl;
        std::cerr << "Output: \n";
        std::cerr << message << '\n';
        std::cerr << "\nPress any key to continue... ";

        std::cin.get();

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    log << message << std::endl;
}
