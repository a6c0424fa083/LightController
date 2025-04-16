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



class ButtonColor {
public:
  static ImVec4 hovered(ImVec4 color) {return ImVec4(color.x + 0.04f, color.y + 0.04f, color.z + 0.04f, color.w);}
  static ImVec4 active(ImVec4 color) {return ImVec4(color.x + 0.09f, color.y + 0.09f, color.z + 0.09f, color.w);}

  static inline auto colorRed = ImVec4(0.25f, 0.0f, 0.0f, 1.0f);
  static inline auto colorGreen = ImVec4(0.0f, 0.25f, 0.0f, 1.0f);
  static inline auto colorBlue = ImVec4(0.0f, 0.0f, 0.25f, 1.0f);
  static inline auto colorYellow = ImVec4(0.25f, 0.25f, 0.0f, 1.0f);
  static inline auto colorPurple = ImVec4(0.25f, 0.0f, 0.25f, 1.0f);
  static inline auto colorTurquoise = ImVec4(0.0f, 0.25f, 0.25f, 1.0f);
  static inline auto colorGray = ImVec4(0.25f, 0.25f, 0.25f, 1.0f);
};



#endif //BUTTONCOLOR_HPP
