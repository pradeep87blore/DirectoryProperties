#ifndef DATA_STORE_H
#define DATA_STORE_H

#include <unordered_map>
#include <list>

#include "DirectoryInfo.h"

using std::unordered_multimap;
using std::hash;
using std::string;
using std::list;

namespace fs = std::experimental::filesystem;

typedef list<DirectoryInfo> DirList; 

class DataStore
{
    static unordered_multimap<string, DirList> directories;
    
public:
    DataStore();
    ~DataStore();

    //friend int FindFiles(fs::path dirPath);

    static size_t InsertDirectory(const string sPath);

    static size_t GetDirectoryCount();
};

#endif // DATA_STORE_H