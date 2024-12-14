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
    COLOR_RED     = 0,
    COLOR_GREEN   = 1,
    COLOR_BLUE    = 2,
    COLOR_UV      = 3,
    COLOR_AMBIENT = 4,
    COLOR_WHITE   = 5,
    DIMMER        = 6,
    STROBE        = 7,
    PAN_SLOW      = 8,
    PAN_FAST      = 9,
    TILT_SLOW     = 10,
    TILT_FAST     = 11,
    PAN_SPEED     = 12,
    TILT_SPEED    = 13,
    CHANNEL       = 14,
};

inline std::vector<std::string> chanelFunctionStr = { "Color - Red",     "Color - Green", "Color - Blue", "Color - UV",
                                               "Color - Ambient", "Color - White", "Dimmer",       "Strobe",
                                               "Pan - Slow",      "Pan - Fast",    "Tilt - Slow",  "Tilt - Fast",
                                               "Pan - Speed",     "Tilt - Speed",  "Channel" };

#endif  // CHANNELFUNCTION_HPP
