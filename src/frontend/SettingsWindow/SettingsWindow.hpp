//
//  SettingsWindow.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-12.
//

#ifndef SETTINGSWINDOW_HPP
#define SETTINGSWINDOW_HPP


#include <imgui.h>

#include "frontend/BaseWindow.hpp"
#include "backend/defines.hpp"
#include "backend/GLOBAL.hpp"
#include <frontend/SettingsWindow/ProjectManagerWindow/ProjectManagerWindow.hpp>
#include <frontend/SettingsWindow/LibraryManagerWindow/LibraryManagerWindow.hpp>

class SettingsWindow : BaseWindow {
public:
    ~SettingsWindow();

    void Draw(ImVec2 pos, ImVec2 size);
    void DrawContents();

private:
    ImVec2 _pos;
    ImVec2 _size;

    ProjectManagerWindow *projectManagerWindow = new ProjectManagerWindow();
    LibraryManagerWindow *libraryManagerWindow = new LibraryManagerWindow();
};


#endif //SETTINGSWINDOW_HPP
