
#include <string>
#include "DirectoryInfo.h"

using std::hash;
using std::string;

DirectoryInfo::DirectoryInfo(fs::path path) : fullFilePath(path)
{
    if (fs::is_regular_file(this->fullFilePath)) // A file and not a directory
    {
        // Remove the file name and keep the rest of the path as the directory path
        this->fileSize = fs::file_size(this->fullFilePath);
        string strDirPath = path.generic_string();
        size_t lastSlashPos = strDirPath.rfind('/');
        this->dirPath = fs::path(strDirPath.substr(0, lastSlashPos));
    }
    else if (fs::is_directory(this->fullFilePath))
    {
        this->dirPath = this->fullFilePath;
        this->fileSize = 0; // Set the directory file size to 0
    }
}


DirectoryInfo::~DirectoryInfo()
{

}

fs::path DirectoryInfo::GetDirectoryPath() const
{
    return this->dirPath;
}

bool DirectoryInfo::operator == (const DirectoryInfo& dirInfo) const
{
    return dirInfo.dirPath.generic_string().compare(this->dirPath.generic_string());
}