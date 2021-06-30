#ifndef _VECTOR_2D_H_
#define _VECTOR_2D_H_

class Vector2f
{	
    float _x, _y;

public:
    constexpr Vector2f() : _x(0.f), _y(0.f) {}
    constexpr Vector2f(const float& x, const float& y) : _x(x), _y(y) {}
    constexpr Vector2f(const Vector2f& rhs) = default;

	friend constexpr Vector2f operator+(const Vector2f& lhs, const Vector2f& rhs)
    {
        return Vector2f(lhs._x + rhs._x, lhs._y + rhs._y);
    }

    friend constexpr Vector2f operator-(const Vector2f& lhs, const Vector2f& rhs)
    {
        return Vector2f(lhs._x - rhs._x, lhs._y - rhs._y);
    }

	friend constexpr float operator*(const Vector2f& lhs, const Vector2f& rhs)
	{
        return lhs._x * rhs._x + lhs._y * rhs._y;
	}

	constexpr Vector2f operator*(const float& val) const
	{
        return Vector2f(_x * val, _y * val);
	}

	constexpr Vector2f operator/(const float& val) const
    {
        return Vector2f(_x / val, _y / val);
    }

    constexpr Vector2f Normalize() const
    {
        return Vector2f(_x / GetLength(), _y / GetLength());
    }

    const float GetLength() const
    {
        return sqrtf(powf(_x, 2.f) + powf(_y, 2.f));
    }

    const float& GetX() const { return _x; }
    const float& GetY() const { return _y; }
};

#endif
