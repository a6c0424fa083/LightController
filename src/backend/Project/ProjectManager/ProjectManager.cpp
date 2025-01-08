//
//  ProjectManager.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-21.
//

#include "ProjectManager.hpp"

uint8_t ProjectManager::addProject(Project project, std::string name)
{
    // base directory to the light "database"
    const std::string baseDir = std::filesystem::current_path().string() + "/" + std::string(PROJECTS_PATH);

    // check for existence of directory
    if (!std::filesystem::exists(baseDir) || !std::filesystem::is_directory(baseDir)) return 2;

    // the path to the library file
    std::string projectFilePath = baseDir + name + ".LCproj";


    // check if the project-name already exists
    if (std::filesystem::exists(projectFilePath)) {
        return 8; // duplicate project error
    }
        std::fstream createFile(projectFilePath, std::ios::binary | std::ios::out);
        if (!createFile.is_open()) return 2;  // Filesystem error


        createFile.write(reinterpret_cast<char *>(&project), sizeof(Project));

        createFile.close();

    return 0;
}


uint8_t ProjectManager::deleteProjectByIndex(size_t index)
{
    // UNDER CONSTRUCTION -- PASTED FROM AddLightWindow
    if (index >= GLOBAL::LIGHTFILEMANAGER::lightsLibrary.size()) return 1;
    // base directory to the light "database"
    const std::string baseDir = std::filesystem::current_path().string() + "/" + std::string(LIGHT_LIBRARY_PATH);

    // Check if the base directory exists
    if (!std::filesystem::exists(baseDir) || !std::filesystem::is_directory(baseDir))
    {
        fprintf(stderr, "Base directory does not exist or is invalid\n");
        return 2;  // filesystem error
    }


    // the path to the library file
    std::string lightsFilePath = baseDir + "library.LClib";

    if (!std::filesystem::exists(lightsFilePath))
    {
        fprintf(stderr, "File does not exist: \n");
        return 2;  // File error
    }

    std::fstream file(lightsFilePath, std::ios::binary | std::ios::in | std::ios::out);
    if (!file.is_open())
    {
        fprintf(stderr, "Error opening file: \n");
        return 2;  // File error
    }

    Light lastLight;

    // replace element with last element

    // get last element
    file.seekg(static_cast<std::streamoff>((GLOBAL::LIGHTFILEMANAGER::lightsLibrary.size() - 1) * sizeof(Light)));
    size_t lastLightPos = file.tellg();
    file.read(reinterpret_cast<char *>(&lastLight), sizeof(Light));

    // jump to the beginning of the file
    file.seekg(0);

    // go to the beginning of the latest read in light
    file.seekp(static_cast<ssize_t>(index * sizeof(Light)));

    // replace the light with the last light
    file.write(reinterpret_cast<char *>(&lastLight), sizeof(Light));


    file.close();
    std::filesystem::resize_file(lightsFilePath, lastLightPos);

    return 0;  // Success
}

uint8_t ProjectManager::loadProjectsToVector()
{
    GLOBAL::PROJECT::projects.clear();
    for (const auto &entry : std::filesystem::directory_iterator(PROJECTS_PATH))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".LCproj") { GLOBAL::PROJECT::projects.push_back(entry.path()); }
    }
    return 0;
}
