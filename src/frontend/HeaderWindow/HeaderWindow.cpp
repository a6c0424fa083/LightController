//
//  HeaderWindow.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-11.
//

#include "HeaderWindow.hpp"

#include <backend/GLOBAL.hpp>
#include <dispatch/data.h>

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
                                        ImVec2(_pos.x + _size.x * (static_cast<float>(GLOBAL::HEADERWINDOW::progressBarProg) / 255.0F), _pos.y + progressBarThickness / 2.0f),
                                        ImGui::ColorConvertFloat4ToU32(GLOBAL::HEADERWINDOW::progressBarColor),
                                        progressBarThickness);

    // draw borderline 1
    constexpr auto line1StartPos = ImVec2(_pos.x, _pos.y + progressBarThickness + borderMargin - (lineThickness / 2.0f));
    ImGui::GetWindowDrawList()->AddLine(ImVec2(line1StartPos),
                                        ImVec2(_pos.x + _size.x, line1StartPos.y),
                                        ImGui::ColorConvertFloat4ToU32(ImVec4(0.6F, 0.6F, 0.6F, 1.0F)),
                                        lineThickness);

    // draw individual buttons leading to the main 'areas' of the program
    constexpr auto buttonStartPos = ImVec2(saveMargin, line1StartPos.y + borderMargin);
    constexpr auto buttonSize = ImVec2((_size.x - (static_cast<float>(GLOBAL::HEADERWINDOW::sections.size()) + 1.0F) * saveMargin) /
                                     static_cast<float>(GLOBAL::HEADERWINDOW::sections.size()),
                                 ImGui::CalcTextSize("XXX").y + 2.0F * saveMargin);
    for (size_t i = 0; i < GLOBAL::HEADERWINDOW::sections.size(); i++)
    {
        // set new cursor position based on i
        ImGui::SetCursorPos(ImVec2(buttonStartPos.x+
            static_cast<float>(i) * saveMargin +
                static_cast<float>(i) * buttonSize.y,
            buttonStartPos.y));

        // draw button using index i of header_titles vector
        if (ImGui::Button("Test",
                          buttonSize))
          GLOBAL::HEADERWINDOW::activeSection = i;
    }

    // draw borderline 2
    constexpr auto line2StartPos = ImVec2(_pos.x, buttonStartPos.y + ImGui::CalcTextSize("XXX").y + 2.0F * saveMargin + borderMargin - (lineThickness / 2.0f));
    ImGui::GetWindowDrawList()->AddLine(ImVec2(line2StartPos),
                                        ImVec2(_pos.x + _size.x, line2StartPos.y),
                                        ImGui::GetColorU32(ImGuiCol_TextDisabled),
                                        lineThickness);
}

ImVec2 HeaderWindow::getWindowSize() {
    //static double height = 0;

    // line
    //result += lineThickness;

    // boarderMargin


    return ImVec2(io_width, 50.0F);
}
