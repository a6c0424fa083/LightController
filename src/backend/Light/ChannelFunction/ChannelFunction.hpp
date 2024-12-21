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
    PAN_FAST      = 9,
    PAN_SLOW      = 10,
    TILT_FAST     = 11,
    TILT_SLOW     = 12,
    PAN_SPEED     = 13,
    TILT_SPEED    = 14,
    MOTOR_SPEED   = 15,
    GOBO          = 16,

};

inline std::vector<std::string> channelFunctionStr = { "Channel",     "Red",         "Green",     "Blue",      "UV",
                                                       "Ambient",     "White",       "Dimmer",    "Strobe",    "Pan Corase",
                                                       "Pan Fine",    "Tilt Corase", "Tilt Fine", "Pan Speed", "Tilt Speed",
                                                       "Motor Speed", "Gobo" };

#endif  // CHANNELFUNCTION_HPP
