#ifndef DIRECTORY_INFO_H
#define DIRECTORY_INFO_H

#include <filesystem>
#include <memory>
#include <vector>

namespace fs = std::experimental::filesystem;

class DirectoryInfo
{
    fs::path dirPath;
    fs::path fullFilePath;

    std::uintmax_t fileSize;

    std::uintmax_t numberOfChildFiles;

    std::uintmax_t numberOfChildDirectories;

    std::vector<DirectoryInfo> childDirectories;

    //friend size_t path_hash(const DirectoryInfo & dirPath);
    DirectoryInfo();

public:

    DirectoryInfo(fs::path path);

    ~DirectoryInfo();

    fs::path GetDirectoryPath() const;

    bool operator == (const DirectoryInfo& dirInfo) const;
};

// Hash function for the DirectoryInfo
size_t path_hash(const DirectoryInfo & dirPath);

#endif // DIRECTORY_INFO_H