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
    _pos  = pos;
    _size = size;

    io.FontGlobalScale = fontSize;

    ImGui::PushFont(PAGEFILLING);
    setWindowPosSize(_pos, _size);

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

    if (headerWindowSize.x < 0.1f) headerWindowSize = HeaderWindow::getWindowSize();
    headerWindow->Draw(ImVec2(0.0F, 0.0F), headerWindowSize);

}
