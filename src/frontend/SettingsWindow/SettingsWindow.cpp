//
//  SettingsWindow.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-12.
//

#include "SettingsWindow.hpp"


SettingsWindow::~SettingsWindow() {}

void SettingsWindow::Draw(ImVec2 pos, ImVec2 size)
{
    _pos               = pos;
    _size              = size;
    io.FontGlobalScale = fontSize;

    ImGui::PushFont(SUBTITLE);
    setWindowPosSize(_pos, _size);

    ImGui::Begin("SettingsWindow", nullptr, STATIC__NO_VISUALS);

    DrawContents();

    ImGui::End();
    ImGui::PopFont();
}

void SettingsWindow::DrawContents()
{
    projectManagerWindow->Draw(ImVec2(_pos.x + saveMargin, _pos.y + saveMargin),
                               ImVec2(_size.x / 2.0f - 1.5f * saveMargin, _size.y - 2 * saveMargin));
    libraryManagerWindow->Draw(ImVec2(_pos.x + _size.x / 2.0f + 0.5f * saveMargin, _pos.y + saveMargin),
                               ImVec2(_size.x / 2.0f - 1.5f * saveMargin, _size.y - 2 * saveMargin));
}
