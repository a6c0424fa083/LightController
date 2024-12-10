//
//  MasterWindow.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-10.
//

#include "MasterWindow.hpp"

#include <implot.h>

MasterWindow::~MasterWindow() {}

void MasterWindow::Draw(ImVec2 pos, ImVec2 size)
{
    io.FontGlobalScale = fontSize;

    ImGui::PushFont(PAGEFILLING);
    setWindowPosSize(pos, size);

    style.WindowBorderSize = 0.0F;
    style.WindowRounding   = 0.0F;
    style.FrameBorderSize  = 0.0F;
    style.FrameRounding    = 0.0F;

    ImGui::Begin("MasterWindow", nullptr, STATIC__NO_VISUALS | ImGuiWindowFlags_NoBringToFrontOnFocus);

    style.WindowBorderSize = default_WindowBorderSize;
    style.WindowRounding   = default_WindowRounding;
    style.FrameBorderSize  = default_FrameBorderSize;
    style.FrameRounding    = default_FrameRounding;

    DrawContents();

    ImGui::End();
    ImGui::PopFont();
}



void MasterWindow::DrawContents()
{
    char helloWorld[] = "Hello, world!\n";
    ImGui::SetCursorPos(ImVec2(io_width / 2.0f - ImGui::CalcTextSize(helloWorld).x / 2.0f,
                               io_height / 2.0f - ImGui::CalcTextSize(helloWorld).y / 2.0f));
    ImGui::Text("%s", helloWorld);
}
