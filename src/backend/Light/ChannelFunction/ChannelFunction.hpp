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

};

inline std::vector<std::string> channelFunctionStr = { "Channel",     "Color - Red",     "Color - Green", "Color - Blue",
                                                       "Color - UV",  "Color - Ambient", "Color - White", "Dimmer",
                                                       "Strobe",      "Pan - Slow",      "Pan - Fast",    "Tilt - Slow",
                                                       "Tilt - Fast", "Pan - Speed",     "Tilt - Speed" };

#endif  // CHANNELFUNCTION_HPP
