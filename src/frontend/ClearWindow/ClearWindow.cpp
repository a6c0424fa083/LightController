//
//  ClearWindow.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-24.
//

#include "ClearWindow.hpp"

ClearWindow::~ClearWindow() {}

void ClearWindow::Draw(ImVec2 pos, ImVec2 size)
{
    _pos               = pos;
    _size              = size;
    io.FontGlobalScale = fontSize;

    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));

    ImGui::PushFont(PAGEFILLING);
    setWindowPosSize(_pos, _size);

    ImGui::Begin("ClearWindow",
                 nullptr,
                 STATIC__NO_VISUALS | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoInputs);

    DrawContents();

    ImGui::End();
    ImGui::PopFont();

    ImGui::PopStyleColor();
}

void ClearWindow::DrawContents()
{
    const char message[] = "Hello!";
    ImGui::SetCursorPos(ImVec2(io_width / 2.0f - ImGui::CalcTextSize(message).x / 2.0f,
                               io_height / 2.0f - ImGui::CalcTextSize(message).y / 2.0f));

    ImGui::Text("%s", message);
}
