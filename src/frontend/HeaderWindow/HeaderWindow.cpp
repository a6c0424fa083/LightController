//
//  HeaderWindow.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-11.
//

#include "HeaderWindow.hpp"

HeaderWindow::~HeaderWindow() {}

void HeaderWindow::Draw(ImVec2 pos, ImVec2 size)
{
    this->pos          = pos;
    this->size         = size;
    io.FontGlobalScale = fontSize;

    ImGui::PushFont(TITLE);
    setWindowPosSize(this->pos, this->size);

    ImGui::Begin("HeaderWindow", nullptr, STATIC__NO_VISUALS);

    DrawContents();

    ImGui::End();
    ImGui::PopFont();
}



void HeaderWindow::DrawContents()
{
    char helloWorld[] = "Hello, world!\n";
    ImGui::SetCursorPos(ImVec2(size.x / 2.0f - ImGui::CalcTextSize(helloWorld).x / 2.0f,
                               size.y / 2.0f - ImGui::CalcTextSize(helloWorld).y / 2.0f));
    ImGui::Text("%s", helloWorld);
}
