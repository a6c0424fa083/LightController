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

#include <backend/GLOBAL.hpp>
#include <backend/defines.hpp>
#include <frontend/BaseWindow.hpp>

class ProjectManagerWindow : BaseWindow
{
public:
    ~ProjectManagerWindow();

    void Draw(ImVec2 pos, ImVec2 size);
    void DrawContents();

private:
    ImVec2 _pos;
    ImVec2 _size;
};


#endif  // PROJECTMANAGERWINDOW_HPP
