#pragma once
// This file shall be used to capture the info about this project


#if 0

Project purpose: To create a Windows GUI application that can give information about the directories on a hard disk and indicate which folders 
are taking how much of space on the drive. 

Set of features to be provided:

01. The user should be able to sort the directories based on the amount of size they are taking up
02. The user should be able to delete the directories from the GUI
03. The user should be able to open any directory in the Windows explorer
04. The user should be able to open any file with the default windows application for that file type
05. The user should be able to get information about which types of files are taking what segment of the space:
    Thus, we should present a pie chart or bar graph indicating how much of space audio files, video files, compressed files, misc files, are taking
06. The user should be able to add thier own extensions to the file categories. For e.g., if .abc is an audio file, the user should be able to 
    enhance the default categorization by adding this file type to the appropriate categories
07. The user should be able to add their own categories for the file types. E.g., add .blender files into a new 3D models category
08. The user should be able to invoke the application via a context menu, that appears only on directories
09. The user should be able to grant administrator rights to the application.
10. The user should be able to print a report or generate a CSV / Excel file with the directory info



Architecture:
       1. Front end shall be created with WPF and C# (using Expression Blend where required)
       2. The back end shall be C++ (including C++ 11 features and the STL)
       3. There shall be a bridge DLL that talks between these two layers
       4. There shall be DB like storage, that stores the settings. See if we can use a simple encrypted file for this (or even the registry settings)

Notes:
       1. See if you can use concurrency to fetch the children information of different sub folders on different threads
       2. 

The C++ backend should just provide APIs. The front end shall be implemented in MFC, WPF, etc. This is the target. The C++ backend should be a DLL










#endif