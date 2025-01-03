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

class ProjectManager
{
public:
    static uint8_t createProject(const std::string& name);
    //static uint8_t loadProject(std::filesystem::path path);
    //static uint8_t loadProjectsToVector();

};


#endif  // PROJECTMANAGER_HPP
