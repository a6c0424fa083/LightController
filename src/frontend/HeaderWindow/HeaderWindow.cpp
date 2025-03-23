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
    _pos               = pos;
    _size              = size;
    io.FontGlobalScale = fontSize;

    ImGui::PushFont(SUBTITLE);
    setWindowPosSize(_pos, _size);

    style.WindowBorderSize = 0.0F;
    style.WindowRounding   = 0.0F;
    style.FrameBorderSize  = 0.0F;
    style.FrameRounding    = 0.0F;
    style.ChildBorderSize  = 0.0F;
    style.ChildRounding    = 0.0F;

    ImGui::Begin("HeaderWindow", nullptr, STATIC__NO_VISUALS);

    style.WindowBorderSize = default_WindowBorderSize;
    style.WindowRounding   = default_WindowRounding;
    style.FrameBorderSize  = default_FrameBorderSize;
    style.FrameRounding    = default_FrameRounding;
    style.ChildBorderSize  = default_ChildBorderSize;
    style.ChildRounding    = default_ChildRounding;

    DrawContents();

    ImGui::End();
    ImGui::PopFont();
}



void HeaderWindow::DrawContents()
{
    // draw progress bar
    ImGui::GetWindowDrawList()->AddLine(ImVec2(_pos.x, _pos.y + progressBarThickness / 2.0f),
                                        ImVec2(_pos.x + _size.x * (static_cast<float>(GLOBAL::HEADERWINDOW::progressBarProg) / 255.0F),
                                               _pos.y + progressBarThickness / 2.0f),
                                        ImGui::ColorConvertFloat4ToU32(GLOBAL::HEADERWINDOW::progressBarColor),
                                        progressBarThickness);

// draw borderline 1
#define line1StartPosY (_pos.y + progressBarThickness + borderMargin - (lineThickness / 2.0f))
    // ImGui::GetWindowDrawList()->AddLine(ImVec2(_pos.x, line1StartPosY),
    //                                     ImVec2(_pos.x + _size.x, line1StartPosY),
    //                                     ImGui::ColorConvertFloat4ToU32(ImVec4(0.6F, 0.6F, 0.6F, 1.0F)),
    //                                     lineThickness);

// draw individual buttons leading to the main 'areas' of the program
#define buttonStartPosY (line1StartPosY + /*(lineThickness / 2.0f) +*/ borderMargin)
#define buttonSizeX                                                                                \
    ((_size.x - (static_cast<float>(GLOBAL::HEADERWINDOW::sections.size()) + 1.0F) * saveMargin) / \
     static_cast<float>(GLOBAL::HEADERWINDOW::sections.size()))
#define buttonSizeY ImGui::CalcTextSize("XXX").y + 2.0F * saveMargin
    for (size_t i = 0; i < GLOBAL::HEADERWINDOW::sections.size(); i++)
    {
        // set new cursor position based on i
        ImGui::SetCursorPos(ImVec2(saveMargin + static_cast<float>(i) * saveMargin + static_cast<float>(i) * buttonSizeX,
                                   buttonStartPosY - _pos.y));

        // draw button using index i of header_titles vector
        if (ImGui::Button(GLOBAL::HEADERWINDOW::sections.at(i).c_str(), ImVec2(buttonSizeX, buttonSizeY)))
        {
            GLOBAL::HEADERWINDOW::activeSection = i;

            // for closing all sub-windows after button push on header window
            GLOBAL::ADDLIGHTWINDOW::isWindowActive           = false;
            GLOBAL::LIGHTINFOWINDOW::isWindowActive          = false;
            GLOBAL::LISTLIGHTSWINDOW::isWindowActive         = false;
            GLOBAL::SELECTLIGHTWINDOW::isWindowActive        = false;
            GLOBAL::CREATEPROJECTWINDOW::isWindowActive      = false;
            GLOBAL::ARRANGEWINDOW::isEditOptionsWindowActive = false;
        }
    }

// draw borderline 2
#define line2StartPosY \
    (buttonStartPosY + ImGui::CalcTextSize("XXX").y + 2.0F * saveMargin + borderMargin + (lineThickness / 2.0f))
    ImGui::GetWindowDrawList()->AddLine(ImVec2(_pos.x, line2StartPosY),
                                        ImVec2(_pos.x + _size.x, line2StartPosY),
                                        ImGui::ColorConvertFloat4ToU32(ImVec4(0.6F, 0.6F, 0.6F, 1.0F)),
                                        lineThickness);

    idealSize                  = ImVec2(io_width, line2StartPosY + (lineThickness / 2.0f));
    GLOBAL::HEADERWINDOW::size = idealSize;
    GLOBAL::HEADERWINDOW::pos  = _pos;

#undef line1StartPosY
#undef buttonStartPosY
#undef buttonSizeX
#undef buttonSizeY
#undef line2StartPosY
}
