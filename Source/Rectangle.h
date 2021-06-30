#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "Vector2f.h"

class Rectangle
{
	float _left, _top, _width, _height;

public:
	constexpr Rectangle(const float& left, const float& top, const float& width, const float& height)
		: _left(left), _top(top), _width(width), _height(height) {}

	Rectangle(const Vector2f& position, const Vector2f& size) 
		:_left(position.GetX()), _top(position.GetY()), _width(size.GetX()), _height(size.GetY()) {}

	const float& GetTop() const { return _top; }
	const float& GetLeft() const { return _left; }
	constexpr float GetRight() const { return (_left + _width); }
	constexpr float GetBottom() const { return (_top - _height); }

	const Vector2f GetOrigin() const
	{
		return Vector2f(_left, _top);
	}

	constexpr Vector2f GetCenter()
	{
		return Vector2f(_left + _width / 2.f, _top + _height / 2.f);
	}

	const Vector2f GetSize() const
	{
		return Vector2f(_width, _height);
	}

	bool IsContains(const Vector2f& point) const
	{
		return point.GetX() >= _left && point.GetX() <= _left + _width &&
			point.GetY() <= _top && point.GetY() >= _top - _height;
	}

	bool IsContains(const Rectangle& rect) const
	{
		return _left <= rect._left && rect.GetRight() <= GetRight() &&
			_top <= rect._top && rect.GetBottom() <= GetBottom();
	}

	bool IsIntersects(const Rectangle& rect) const
	{
		return !(_left >= rect.GetRight() || GetRight() <= rect._left ||
			_top <= rect.GetBottom() || GetBottom() >= rect._top);
	}
};

#endif
