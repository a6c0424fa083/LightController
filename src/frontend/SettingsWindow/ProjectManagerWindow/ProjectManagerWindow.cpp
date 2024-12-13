//
//  ProjectManagerWindow.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-13.
//

#include "ProjectManagerWindow.hpp"

ProjectManagerWindow::~ProjectManagerWindow() {}

void ProjectManagerWindow::Draw(ImVec2 pos, ImVec2 size)
{
    _pos               = pos;
    _size              = size;
    io.FontGlobalScale = fontSize;

    ImGui::PushFont(TITLE);
    setWindowPosSize(_pos, _size);

    ImGui::Begin("ProjectManagerWindow", nullptr, STATIC__NO_VISUALS);

    DrawContents();

    ImGui::End();
    ImGui::PopFont();
}

void ProjectManagerWindow::DrawContents()
{
    ImGui::SetCursorPos(ImVec2(saveMargin, saveMargin));
    ImGui::Text("Hello, world!");
}
