#include "DataStore.h"
#include <iostream>
#include <string>


unordered_multimap<string, DirList> DataStore::directories;
using std::string;

DataStore::DataStore()
{
    //int **array = 
}


DataStore::~DataStore()
{
}


size_t DataStore::InsertDirectory(const string sPath)
{
    fs::path currentFilePath(sPath);
    DirectoryInfo dirInfo (currentFilePath);
    
    auto it = directories.find(dirInfo.GetDirectoryPath().generic_string());
    if (it == directories.end()) // This means that no previous entry was found for this directory
    {
        DirList list;
        list.push_back(dirInfo);
        std::pair<string, DirList> kvp(dirInfo.GetDirectoryPath().generic_string(), list);
        directories.insert(kvp);
    }
    else
    {
        it->second.push_back(dirInfo); // List already existed, push the new file onto this
    }

    return directories.size();
}



size_t DataStore::GetDirectoryCount()
{   

    return directories.size();
}

