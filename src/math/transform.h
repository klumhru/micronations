#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

typedef struct Transform
{
    float x, y;
    float s;
    float r;

    Transform() : x(0.0f), y(0.0f), s(1.0f), r(0.0f) {}
    Transform(float x_, float y_, float s_, float r_) : x(x_), y(y_), s(s_), r(r_) {}
} Transform;

#endif // _TRANSFORM_H_