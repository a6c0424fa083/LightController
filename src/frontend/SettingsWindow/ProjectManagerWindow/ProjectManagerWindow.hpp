//
//  ProjectManagerWindow.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-13.
//

#ifndef PROJECTMANAGERWINDOW_HPP
#define PROJECTMANAGERWINDOW_HPP


#include <imgui.h>

#include "backend/GLOBAL.hpp"
#include "backend/defines.hpp"
#include "frontend/BaseWindow.hpp"
#include "frontend/SettingsWindow/ProjectManagerWindow/CreateProjectWindow/CreateProjectWindow.hpp"

class ProjectManagerWindow : BaseWindow
{
public:
    ~ProjectManagerWindow();

    void Draw(ImVec2 pos, ImVec2 size);
    void DrawContents();

private:
    ImVec2 _pos;
    ImVec2 _size;

    ImVec2 createProjectWindowSize = ImVec2(0.0f, 0.0f);

    CreateProjectWindow *createProjectWindow = new CreateProjectWindow();
};


#endif  // PROJECTMANAGERWINDOW_HPP
