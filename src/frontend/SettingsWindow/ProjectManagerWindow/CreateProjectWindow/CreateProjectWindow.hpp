//
//  CreateProjectWindow.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-21.
//

#ifndef CREATEPROJECTWINDOW_HPP
#define CREATEPROJECTWINDOW_HPP


#include <imgui.h>

#include "backend/GLOBAL.hpp"
#include "backend/Project/ProjectManager/ProjectManager.hpp"
#include "backend/defines.hpp"
#include "frontend/BaseWindow.hpp"


class CreateProjectWindow : BaseWindow
{
public:
    ~CreateProjectWindow();

    void Draw(ImVec2 pos, ImVec2 size);
    void DrawContents();

    static ImVec2 getIdealWindowSize() { return _idealWindowSize; };

private:
    ImVec2 _pos;
    ImVec2 _size;

    char _name[MAX_PROJECT_LENGTH] = { 0 };

    inline static auto _idealWindowSize = ImVec2(0.0f, 0.0f);
};



#endif  // CREATEPROJECTWINDOW_HPP
