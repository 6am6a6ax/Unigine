#ifndef _COLOR_H_
#define _COLOR_H_

#include <type_traits>

template<typename T> struct Color4
{
	static_assert(std::is_same<int, T>::value ||
                  std::is_same<float, T>::value ||
                  std::is_same<double, T>::value,
                  "Only int, float or double data types are allowed");
	
	T Red, Green, Blue, Alpha;
	
	constexpr Color4(const T& red, const T& green, const T& blue, const T& alpha = {}) noexcept
		: Red(red), Green(green), Blue(blue), Alpha(alpha) {}
};

typedef Color4<int> Color3i;
typedef Color4<float> Color3f;
typedef Color4<double> Color3d;

#endif
