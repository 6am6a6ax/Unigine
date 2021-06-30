#ifndef _DRAW_H_
#define _DRAW_H_

#include <memory>

#include <GL/glew.h>

#include "Color.h"

#include "Unit.h"

#include "Vector2f.h"
#include "Rectangle.h"
#include "QuadTree.h"

inline void Draw(const Vector2f& point, const Color3f& color = Color3f(0.f, 255.f, 0.f))
{
    glPointSize(5.f);
	
    glColor3f(color.Red, color.Green, color.Blue);
	
    glBegin(GL_POINTS);

    glVertex2f(point.GetX(), point.GetY());

    glEnd();
}

inline void Draw(const Vector2f& begin, const Vector2f& end, const Color3f& color = Color3f(255.f, 0.f, 0.f))
{
    glColor3f(color.Red, color.Green, color.Blue);
	
    glBegin(GL_LINES);

    glVertex2f(begin.GetX(), begin.GetY());
    glVertex2f(end.GetX(), end.GetY());
	
    glEnd();
}

inline void Draw(const Unit& unit, const Color3f positionColor = Color3f(0.f, 255.f, 0.f),
    const Color3f lookColor = Color3f(255.f, 0.f, 0.f))
{
    //Draw(unit.GetPosition(), unit.GetLook().Normalize(), lookColor);
    Draw(unit.GetPosition(), positionColor);
}

inline void Draw(const Rectangle& rect, const Color3f& color = Color3f(0.f, 0.f, 255.f))
{
    glColor3f(color.Red, color.Green, color.Blue);
	
    glBegin(GL_LINE_STRIP);

    glVertex2f(rect.GetBottom(),  rect.GetLeft());
    glVertex2f(rect.GetTop(),     rect.GetLeft());
    glVertex2f(rect.GetTop(),     rect.GetRight());
    glVertex2f(rect.GetBottom(),  rect.GetRight());
    glVertex2f(rect.GetBottom(),  rect.GetLeft());
	
    glEnd();
}

inline void Draw(const std::shared_ptr<QuadTree>& quadTree,
    const Color3f& color = Color3f(255.f, 255.f, 255.f))
{
    Draw(quadTree->GetRectangle(), color);

    if (!quadTree->IsLeaf())
        for (const auto& child : quadTree->GetChildren())
            Draw(child, color);
}

#endif
