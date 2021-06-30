#ifndef _UNIT_H_
#define _UNIT_H_

#include "Vector2f.h"
#include "Rectangle.h"

#include "Config.h"
#include "Helper.h"

class Unit
{
	constexpr static float ViewAngle = UNIT_VIEW_ANGLE;
	constexpr static float ViewDistance = UNIT_VIEW_DISTANE;
	
	Vector2f _position;
	Vector2f _look;

public:
	constexpr Unit() : _position(Vector2f()), _look(Vector2f()) {}
	constexpr Unit(const Vector2f& position, const Vector2f& look)
		: _position(position), _look(look) {}

	const Vector2f& GetPosition() const { return _position; }
	constexpr Vector2f GetLook() const { return _look; }

	static constexpr float GetViewAngle() { return ViewAngle; }
	static constexpr float GetViewDistance() { return ViewDistance; }

	const Vector2f& SetPosition(const Vector2f& position)
	{
		return _position = position;
	}

	const Vector2f& SetLook(const Vector2f& look)
	{
		return _look = look;
	}
};

// View angle check
//--------------------------------------------------
bool Check(const Unit& a, const Unit& b)
{
	Vector2f dist = b.GetPosition() - a.GetPosition();
	float distLength = dist.GetLength();

	Vector2f viewNorm = a.GetLook().Normalize();
	Vector2f distNorm = dist.Normalize();

	float viewNormLength = viewNorm.GetLength();
	float distNormLength = distNorm.GetLength();

	float result = acosf((a.GetLook().Normalize() * dist.Normalize()));

	if (RadiansToDegrees(result) <= UNIT_VIEW_ANGLE)
		return true;

	return false;
}

#endif