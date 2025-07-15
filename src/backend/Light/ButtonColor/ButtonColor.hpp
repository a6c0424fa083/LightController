//
//  ButtonColor.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2025-03-27.
//

#ifndef BUTTONCOLOR_HPP
#define BUTTONCOLOR_HPP

#include <imgui.h>
#include <vector>


enum BUTTON_COLOR : uint8_t
{
    RED       = 0,
    GREEN     = 1,
    BLUE      = 2,
    YELLOW    = 3,
    PURPLE    = 4,
    TURQUOISE = 5,
    GRAY      = 6,
};

inline std::vector<std::string> buttonColorStr = {
    "Red", "Green", "Blue", "Yellow", "Purple", "Turquoise", "Gray",
};


class ButtonColor
{
public:
    static ImVec4 color(const BUTTON_COLOR color)
    {
        const ImVec4 _color = getColorFromEnum(color);
        return { _color.x, _color.y, _color.z, _color.w };
    }
    static ImVec4 hovered(const BUTTON_COLOR color)
    {
        const ImVec4 _color = getColorFromEnum(color);
        return { _color.x + 0.04f, _color.y + 0.04f, _color.z + 0.04f, _color.w };
    }
    static ImVec4 active(const BUTTON_COLOR color)
    {
        const ImVec4 _color = getColorFromEnum(color);
        return { _color.x + 0.09f, _color.y + 0.09f, _color.z + 0.09f, _color.w };
    }

    static ImVec4 brightHovered(const BUTTON_COLOR color)
    {
        const ImVec4 _color = getColorFromEnum(color);
        return { _color.x + 0.04f + 0.15f, _color.y + 0.04f + 0.15f, _color.z + 0.04f + 0.15f, _color.w };
    }
    static ImVec4 brightActive(const BUTTON_COLOR color)
    {
        const ImVec4 _color = getColorFromEnum(color);
        return { _color.x + 0.09f + 0.15f, _color.y + 0.09f + 0.15f, _color.z + 0.09f + 0.15f, _color.w };
    }

private:
    static ImVec4 getColorFromEnum(BUTTON_COLOR buttonColor)
    {
        switch (buttonColor)
        {
            case RED: return {0.25f, 0.0f, 0.0f, 1.0f};
            case GREEN: return {0.0f, 0.25f, 0.0f, 1.0f};
            case BLUE: return {0.0f, 0.0f, 0.25f, 1.0f};
            case YELLOW: return {0.25f, 0.25f, 0.0f, 1.0f};
            case PURPLE: return {0.25f, 0.0f, 0.25f, 1.0f};
            case TURQUOISE: return {0.0f, 0.25f, 0.25f, 1.0f};
            case GRAY: return {0.25f, 0.25f, 0.25f, 1.0f};
            default: return {0.25f, 0.25f, 0.25f, 1.0f};
        }
    }
};



#endif  // BUTTONCOLOR_HPP
