#pragma once

#include <string>
#include <fstream>
inline void Logger(std::wstring logMsg) {

    std::string filePath = "C:/New folder/log_1.txt";
    std::ofstream ofs(filePath.c_str(), std::ios_base::out | std::ios_base::app);

    if (ofs.is_open())
    {
        // Convert the log message to narrow string
        std::string narrowLogMsg(logMsg.begin(), logMsg.end());

        // Write the log message to the file
        ofs << narrowLogMsg << std::endl;

        // Close the file
        ofs.close();
    }
}