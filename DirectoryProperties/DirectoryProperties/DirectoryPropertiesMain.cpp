// C++ and Windows Header files:
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <strsafe.h>
#include <conio.h>
#include <filesystem>
#include <set>

// Local Header files:
#include "DirectoryPropertiesMain.h"
#include "ErrorCodes.h"
#include "Logger.h"
#include "Utilities.h"
#include "DataStore.h"
using std::string;
using std::set;

namespace fs = std::experimental::filesystem;




// This reads a directory and prints all the folders present in it
int FindFiles(fs::path dirPath)
{
    fs::path parentPath = "";

    int iFileCounter = 0, iDirectoryCounter = 0;
    
    set<string> directoryNames;

    for (auto & p : fs::recursive_directory_iterator(dirPath))
    {
        try
        {
            DataStore::InsertDirectory(p.path().generic_string());
        }
        catch (fs::filesystem_error ex)
        {
            std::cout << ex.what() << std::endl;
        }
    }

    std::cout << "File count " << iFileCounter << std::endl;
    std::cout << "Directory Count " << DataStore::GetDirectoryCount() << std::endl;
    std::cout << "Done" << std::endl;
    return EC_NO_ERROR;
}


int main()
{
    fs::path dirPath = L"C:/Users/bangalpr/OneDrive - Hewlett Packard Enterprise/Desktop/Misc/10th July COs 719 720 1796";
    FindFiles(dirPath);

    ADDLOG(dirPath.generic_string(), LL_INFO);

    _getch();
}
