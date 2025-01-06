//
//  Project.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-21.
//

#include "Project.hpp"

void loadProjectsFromDirectory()
{
    for (const auto &entry : std::filesystem::directory_iterator(PROJECTS_PATH))
    {
        if (entry.is_regular_file()) { GLOBAL::PROJECT::projects.push_back(entry.path()); }
    }
}