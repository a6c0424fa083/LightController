//
//  ProjectManager.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-21.
//

#include "ProjectManager.hpp"

uint8_t ProjectManager::createProject(const std::string &name)
{
    std::filesystem::path projectPath = std::filesystem::path(std::string(PROJECTS_PATH) + name);
    return 0;
}

uint8_t ProjectManager::loadProjectsToVector()
{
    for (const auto &entry : std::filesystem::directory_iterator(PROJECTS_PATH))
    {
        if (entry.is_regular_file()) { GLOBAL::PROJECT::projects.push_back(entry.path()); }
    }
}
