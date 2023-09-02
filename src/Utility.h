#ifndef UTILITY_H
#define UTILITY_H

namespace VNGin {
    struct ColorRGBA {
        unsigned short r;
        unsigned short g;
        unsigned short b;
        unsigned short a;

        const static ColorRGBA black;
        const static ColorRGBA gray;
        const static ColorRGBA silver;
        const static ColorRGBA white;
        const static ColorRGBA navy;
        const static ColorRGBA blue;
        const static ColorRGBA teal;
        const static ColorRGBA aqua;
        const static ColorRGBA green;
        const static ColorRGBA lime;
        const static ColorRGBA olive;
        const static ColorRGBA yellow;
        const static ColorRGBA maroon;
        const static ColorRGBA red;
        const static ColorRGBA purple;
        const static ColorRGBA fuchsia;
    };
}

#endif