//
//  ProjectManager.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-21.
//

#include "ProjectManager.hpp"

#include <backend/Patch/PatchManager/PatchManager.hpp>

uint8_t ProjectManager::saveProject(const std::string &name)
{
    updateCurrentProjectStruct();

    // base directory to the light "database"
    const std::string baseDir = std::filesystem::current_path().string() + "/" + std::string(PROJECTS_PATH);

    // check for existence of directory
    if (!std::filesystem::exists(baseDir) || !std::filesystem::is_directory(baseDir)) return 2;

    // the path to the library file
    std::string projectFilePath = baseDir + name + ".LCproj";


    // check if the project-name already exists
    if (std::filesystem::exists(projectFilePath))
    {
        return 8;  // duplicate project error
    }
    std::fstream createFile(projectFilePath, std::ios::binary | std::ios::out);
    if (!createFile.is_open()) return 2;  // Filesystem error


    createFile.write(reinterpret_cast<char *>(&GLOBAL::PROJECT::currentProject), sizeof(Project));

    createFile.close();

    return 0;
}

uint8_t ProjectManager::recallProject(size_t index)
{
    std::string projectFilePath = GLOBAL::PROJECT::projects.at(index).string();

    printf("Path: %s\n", projectFilePath.c_str());


    // check if the project-name exists else throw error
    if (!std::filesystem::exists(projectFilePath))
    {
        return 8;  // duplicate project error
    }
    std::fstream createFile(projectFilePath, std::ios::binary | std::ios::in);
    if (!createFile.is_open())
    {
        printf("Error 2\n");
        return 2;
    }  // Filesystem error


    Project _project;
    createFile.read(reinterpret_cast<char *>(&_project), sizeof(Project));

    GLOBAL::PROJECT::currentProject = _project;

    printf("read file to prject struct\n");

    createFile.close();

    unpackCurrentProjectStruct();

    return 0;
}


uint8_t ProjectManager::deleteProjectByIndex(size_t index)
{
    if (!GLOBAL::PROJECT::newProject)
    {
        if (!std::filesystem::exists(GLOBAL::PROJECT::projects.at(index))) { return 1; }
        std::filesystem::remove(GLOBAL::PROJECT::projects.at(index));
    }

    return 0;  // Success
}

uint8_t ProjectManager::loadProjectsToVector()
{
    GLOBAL::PROJECT::projects.clear();
    for (const auto &entry : std::filesystem::directory_iterator(PROJECTS_PATH))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".LCproj")
        {
            GLOBAL::PROJECT::projects.push_back(entry.path());
        }
    }
    return 0;
}

uint8_t ProjectManager::updateCurrentProjectStruct()
{
    GLOBAL::PROJECT::currentProject = Project(GLOBAL::PATCH::patchLights);
    return 0;
}


uint8_t ProjectManager::unpackCurrentProjectStruct()
{
    GLOBAL::PATCH::patchLights.clear();
    for (size_t i = 0; i < GLOBAL::PROJECT::currentProject._validLights; i++)
    {
        GLOBAL::PATCH::patchLights.push_back(GLOBAL::PROJECT::currentProject._lights[i]);
    }

    PatchManager::reloadPatchButtonsFromVector2();
    printf("unpacked project struct\n");
    return 0;
}
