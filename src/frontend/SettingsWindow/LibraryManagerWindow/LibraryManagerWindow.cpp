//
//  LibraryManagerWindow.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-13.
//

#include "LibraryManagerWindow.hpp"

LibraryManagerWindow::~LibraryManagerWindow() {}

void LibraryManagerWindow::Draw(ImVec2 pos, ImVec2 size)
{
    _pos               = pos;
    _size              = size;
    io.FontGlobalScale = fontSize;

    ImGui::PushFont(TITLE);
    setWindowPosSize(_pos, _size);

    ImGui::Begin("LibraryManagerWindow", nullptr, STATIC__NO_VISUALS);

    DrawContents();

    ImGui::End();
    ImGui::PopFont();
}

void LibraryManagerWindow::DrawContents()
{
    ImGui::SetCursorPos(ImVec2(_size.x / 2.0f - (ImGui::CalcTextSize("Add new Light").x + 2 * saveMargin) / 2.0f, saveMargin));
    if (ImGui::Button("Add new Light",
                      ImVec2(ImGui::CalcTextSize("Add new Light").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin)))
        GLOBAL::ADDLIGHTWINDOW::isWindowActive = true;


    addLightWindowSize = AddLightWindow::getIdealWindowSize();
    if (GLOBAL::ADDLIGHTWINDOW::isWindowActive)
        addLightWindow->Draw(ImVec2(saveMargin, GLOBAL::HEADERWINDOW::pos.y + GLOBAL::HEADERWINDOW::size.y + saveMargin),
                             addLightWindowSize);
}
