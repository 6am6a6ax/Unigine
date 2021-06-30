#ifndef _QUAD_TREE_H_
#define _QUAD_TREE_H_

#include <array>
#include <memory>
#include <vector>

#include "Vector2f.h"
#include "Rectangle.h"

#include "Unit.h"

class QuadTree
{
	static constexpr auto Threshold = std::size_t(4);

	Rectangle _rectangle;
	std::vector<Unit> _values;

	std::array<std::shared_ptr<QuadTree>, static_cast<std::size_t>(4)> _children;

public:
	QuadTree(const Rectangle& rectangle) : _rectangle(rectangle) {}

	const QuadTree* Subdivide(const Rectangle& rectangle)
	{
		const auto origin = rectangle.GetOrigin();
		const auto size = rectangle.GetSize() / static_cast<float>(2);

		for (std::size_t i = 0; i < _children.size(); i++)
		{
			switch (i)
			{
			// North West
			case 0:
				_children[i] = std::make_shared<QuadTree>(Rectangle(origin, size)); break;
			// North East
			case 1:
				_children[i] = std::make_shared<QuadTree>(Rectangle(Vector2f(origin.GetX() + size.GetX(),
					origin.GetY()), size)); break;
			// South West
			case 2:
				_children[i] = std::make_shared<QuadTree>(Rectangle(Vector2f(origin.GetX(), 
					origin.GetY() - size.GetY()), size)); break;
			// South East
			case 3:
				_children[i] = std::make_shared<QuadTree>(Rectangle(Vector2f(origin.GetX() + size.GetX(), 
					origin.GetY() - size.GetY()), size));
			}
		}

		return this;
	}

	const std::vector<Unit>& Query(const Rectangle& rect,
		std::vector<Unit>* result = new std::vector<Unit>()) const
	{
		if (!_rectangle.IsIntersects(rect))
			return *result;

		for (const auto& value : _values)
			if (rect.IsContains(value.GetPosition()))
				result->push_back(value);

		if (!IsLeaf())
			for (const auto& child : _children)
				child->Query(rect, result);

		return *result;
	}

	const std::vector<Unit>& Query(const Unit& unit,
		std::vector<Unit>* result = new std::vector<Unit>()) const
	{
		return Query(Rectangle(unit.GetPosition().GetX() - Unit::GetViewDistance(), unit.GetPosition().GetY() + Unit::GetViewDistance(),
			Unit::GetViewDistance(), Unit::GetViewDistance()), result);
	}

	bool Insert(const Unit& unit)
	{
		if (_rectangle.IsContains(unit.GetPosition()))
		{
			if (_values.size() != Threshold)
			{
				_values.push_back(unit);

				return true;
			}

			if (IsLeaf())
				for (const auto& child : Subdivide(_rectangle)->_children)
					child->Insert(unit);

			else
				for (const auto& child : _children)
					child->Insert(unit);
		}

		return false;
	}

	bool IsLeaf() const
	{
		return !static_cast<bool>(_children[0]);
	}

	const Rectangle& GetRectangle() const
	{
		return _rectangle;
	}

	const std::array<std::shared_ptr<QuadTree>, 4>& GetChildren() const
	{
		return _children;
	}
};

#endif