//
//  defines.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-10.
//

// NOTE: Some graphical related things are defined in the BaseWindow class

#ifndef DEFINES_HPP
#define DEFINES_HPP


#include <string>
#include <vector>

#include <imgui.h>

#define MASTER_WINDOW_WIDTH  800
#define MASTER_WINDOW_HEIGHT 480

#define style ImGui::GetStyle()

#define io ImGui::GetIO()

#define io_width  io.DisplaySize.x
#define io_height io.DisplaySize.y

#define STATIC__NO_VISUALS                                                                                             \
    (ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | \
     ImGuiWindowFlags_NoScrollbar)

enum USER_FONT
{
    PAGE_FILLING,
    TITLE,
    SUBTITLE,
    TEXT,
    INFORMATION,
    NUMBER
};

#define PAGEFILLING io.Fonts->Fonts[USER_FONT::PAGE_FILLING]
#define TITLE       io.Fonts->Fonts[USER_FONT::TITLE]
#define SUBTITLE    io.Fonts->Fonts[USER_FONT::SUBTITLE]
#define TEXT        io.Fonts->Fonts[USER_FONT::TEXT]
#define INFORMATION io.Fonts->Fonts[USER_FONT::INFORMATION]
#define NUMBER      io.Fonts->Fonts[USER_FONT::NUMBER]

#define MONACO_FONT_PATH     "../applicationData/fonts/Monaco.ttf"      // relative to executable
#define ARIALBLACK_FONT_PATH "../applicationData/fonts/ArialBlack.ttf"  // relative to executable
#define ARIAL_FONT_PATH      "../applicationData/fonts/Arial.ttf"       // relative to executable
#define ARIALBOLD_FONT_PATH  "../applicationData/fonts/ArialBold.ttf"   // relative to executable

#define MAX_LIGHT_NAME_LENGTH 64

#define MAX_LIGHT_MANUFACTURER_LENGTH 64

#define LIGHT_LIBRARY_PATH "../applicationData/LightLibrary/"


#define MAX_PROJECT_NAME_LENGTH 64

#define PROJECTS_PATH "../applicationData/Projects/"

#endif  // DEFINES_HPP
