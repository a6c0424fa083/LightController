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
    ImGui::SetCursorPos(ImVec2(_size.x / 2.0f - (ImGui::CalcTextSize("Projects").x + 2 * saveMargin) / 2.0f, saveMargin));
    if (ImGui::Button("Projects",
                      ImVec2(ImGui::CalcTextSize("Projects").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin)))
    {
        GLOBAL::CREATEPROJECTWINDOW::isWindowActive = true;
    }


    createProjectWindowSize = CreateProjectWindow::getIdealWindowSize();
    if (GLOBAL::CREATEPROJECTWINDOW::isWindowActive)
        createProjectWindow->Draw(ImVec2(saveMargin, GLOBAL::HEADERWINDOW::pos.y + GLOBAL::HEADERWINDOW::size.y + saveMargin),
                                  createProjectWindowSize);
}
