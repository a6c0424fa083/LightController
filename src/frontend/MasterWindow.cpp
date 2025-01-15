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
    idealHeaderWindowSize = HeaderWindow::getIdealSize();

    // TODO: add proper idealSize to GLOBAL for easy reference (partly already there...)
    patchWindowSize    = ImVec2(io_width - 2 * saveMargin, io_height - idealHeaderWindowSize.y - 2 * saveMargin);
    settingsWindowSize = ImVec2(io_width - 2 * saveMargin, io_height - idealHeaderWindowSize.y - 2 * saveMargin);
    arrangeWindowSize  = ImVec2(io_width - 2 * saveMargin, io_height - idealHeaderWindowSize.y - 2 * saveMargin);

    headerWindow->Draw(ImVec2(0.0f, 0.0f), idealHeaderWindowSize);


    switch (GLOBAL::HEADERWINDOW::activeSection)
    {
        case 0: patchWindow->Draw(ImVec2(saveMargin, idealHeaderWindowSize.y + saveMargin), patchWindowSize); break;
        case 1: arrangeWindow->Draw(ImVec2(saveMargin, idealHeaderWindowSize.y + saveMargin), arrangeWindowSize); break;
        case 2: break;
        case 3: break;
        case 4: settingsWindow->Draw(ImVec2(saveMargin, idealHeaderWindowSize.y + saveMargin), settingsWindowSize); break;
        default: break;
    }


    // must come at the end of the windows
    // clearWindow->Draw(ImVec2(0.0f, 0.0f), ImVec2(io_width, io_height));
}
