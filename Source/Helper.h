#ifndef _HELPER_H_
#define _HELPER_H_

#define _USE_MATH_DEFINES
#include <math.h>

const float DegreesToRadians(const float& degrees)
{
    return degrees * (M_PI / 180.f);
}

const float RadiansToDegrees(const float& radians)
{
    return radians * (180.f / M_PI);
}

#endif