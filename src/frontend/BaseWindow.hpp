//
//  BaseWindow.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-10.
//

#ifndef BASEWINDOW_HPP
#define BASEWINDOW_HPP


#include <imgui.h>


class BaseWindow
{
public:
    static inline void setWindowPosSize(ImVec2 pos, ImVec2 size)
    {
        ImGui::SetNextWindowPos(pos);
        ImGui::SetNextWindowSize(size);
    }

public:
    inline static auto  default_ImGuiCol_TableBorderStrong = ImVec4(1.0, 1.0, 1.0, 1.0);
    inline static auto  default_ImGuiCol_TableBorderLight  = ImVec4(1.0, 1.0, 1.0, 1.0);
    inline static auto  default_ImGuiCol_Button            = ImVec4(0.11F, 0.11F, 0.11F, 1.0F);
    inline static auto  default_ImGuiCol_ButtonHovered     = ImVec4(0.14F, 0.14F, 0.14F, 1.0F);
    inline static auto  default_ImGuiCol_ButtonActive      = ImVec4(0.23F, 0.23F, 0.23F, 1.0F);
    inline static auto  red_ImGuiCol_Button                = ImVec4(0.31F, 0.11F, 0.11F, 1.0F);
    inline static auto  red_ImGuiCol_ButtonHovered         = ImVec4(0.34F, 0.14F, 0.14F, 1.0F);
    inline static auto  red_ImGuiCol_ButtonActive          = ImVec4(0.43F, 0.23F, 0.23F, 1.0F);
    inline static auto  green_ImGuiCol_Button              = ImVec4(0.11F, 0.31F, 0.11F, 1.0F);
    inline static auto  green_ImGuiCol_ButtonHovered       = ImVec4(0.14F, 0.34F, 0.14F, 1.0F);
    inline static auto  green_ImGuiCol_ButtonActive        = ImVec4(0.23F, 0.43F, 0.23F, 1.0F);
    inline static auto  darkgreen_ImGuiCol_Button          = ImVec4(0.055F, 0.16F, 0.055F, 1.0F);
    inline static auto  darkgreen_ImGuiCol_ButtonHovered   = ImVec4(0.070F, 0.19F, 0.070F, 1.0F);
    inline static auto  darkgreen_ImGuiCol_ButtonActive    = ImVec4(0.115F, 0.28F, 0.115F, 1.0F);
    inline static auto  default_ImGuiCol_WindowBg          = ImVec4(0.0F, 0.0F, 0.0F, 1.0F);
    inline static auto  default_ImGuiCol_ChildBg           = ImVec4(0.0F, 0.0F, 0.0F, 1.0F);
    inline static auto  default_ImGuiCol_FrameBg           = ImVec4(0.11F, 0.11F, 0.11F, 1.0F);
    inline static auto  default_WindowPadding              = ImVec2(0.0F, 0.0F);
    inline static auto  default_FramePadding               = ImVec2(0.0F, 0.0F);
    inline static float default_WindowBorderSize           = 1.0F;
    inline static float default_WindowRounding             = 5.0F;
    inline static float default_FrameBorderSize            = 1.0F;
    inline static float default_FrameRounding              = 5.0F;
    inline static float default_ChildBorderSize            = 1.0F;
    inline static float default_ChildRounding              = 5.0F;

    inline static float fontSize     = 0.5F;
    inline static float saveMargin   = 5.0F;
    inline static float borderMargin = (2.0F / 5.0F) * saveMargin;
};


#endif  // BASEWINDOW_HPP
