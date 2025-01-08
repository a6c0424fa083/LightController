//
//  ProjectManager.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-21.
//

#ifndef PROJECTMANAGER_HPP
#define PROJECTMANAGER_HPP


#include <filesystem>
#include <fstream>

#include "backend/GLOBAL.hpp"
#include "backend/defines.hpp"
#include "backend/Project/Project.hpp"


class ProjectManager
{
public:
    static uint8_t addProject(Project project, std::string name);
    static uint8_t deleteProjectByIndex(size_t index);
    static uint8_t loadProjectsToVector();
};


#endif  // PROJECTMANAGER_HPP
