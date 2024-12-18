//
//  ChannelFunction.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-14.
//

#ifndef CHANNELFUNCTION_HPP
#define CHANNELFUNCTION_HPP


#include <cstdint>
#include <string>
#include <vector>

enum CHANNEL_FUNCTION : uint8_t
{
    CHANNEL       = 0,
    COLOR_RED     = 1,
    COLOR_GREEN   = 2,
    COLOR_BLUE    = 3,
    COLOR_UV      = 4,
    COLOR_AMBIENT = 5,
    COLOR_WHITE   = 6,
    DIMMER        = 7,
    STROBE        = 8,
    PAN_SLOW      = 9,
    PAN_FAST      = 10,
    TILT_SLOW     = 11,
    TILT_FAST     = 12,
    PAN_SPEED     = 13,
    TILT_SPEED    = 14,
    P_T_SPEED     = 15,
    GOBO          = 16,

};

inline std::vector<std::string> channelFunctionStr = { "Channel",    "Red",       "Green",       "Blue",      "UV",
                                                       "Ambient",    "White",     "Dimmer",      "Strobe",    "Pan Fine",
                                                       "Pan Corase", "Tilt Fine", "Tilt Corase", "Pan Speed", "Tilt Speed",
                                                       "P/T Speed",  "Gobo" };

#endif  // CHANNELFUNCTION_HPP
