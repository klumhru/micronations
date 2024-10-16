#ifndef _NODE_H_
#define _NODE_H_

#include <vector>
#include <memory>
#include <memory_resource>

#include <SDL3/SDL.h>

#include "math/transform.h"

class Node : public std::enable_shared_from_this<Node>
{
protected:
    Transform transform;

public:
    using WeakNodePtr = std::weak_ptr<Node>;
    using NodePtr = std::shared_ptr<Node>;

    explicit Node(std::pmr::memory_resource *memRes = std::pmr::get_default_resource())
        : children(memRes), transform() {}
    virtual ~Node();

    void SetPos(float x_, float y_)
    {
        transform.x = x_;
        transform.y = y_;
    }

    float GetX() const
    {
        return transform.x;
    }

    float GetY() const
    {
        return transform.y;
    }

    void SetScale(float s_)
    {
        transform.s = s_;
    }

    void SetRotation(float r_)
    {
        transform.r = r_;
    }

    void AddChild(const NodePtr &child)
    {
        children.push_back(child);
        child->parent = shared_from_this();
    }

    void RemoveChild(const NodePtr &child)
    {
        children.erase(std::remove(children.begin(), children.end(), child), children.end());
        child->parent.reset();
    }

public:
    void Update(float dt)
    {
        OnUpdate(dt);
        for (auto &child : children)
        {
            child->Update(dt);
        }
    }

    void Render(SDL_Renderer *renderer)
    {
        OnRender(renderer);
        for (auto &child : children)
        {
            child->Render(renderer);
        }
    }

protected:
    virtual void OnUpdate(float dt) = 0;
    virtual void OnRender(SDL_Renderer *renderer) = 0;
    std::pmr::vector<NodePtr> &GetChildren() { return children; }

private:
    WeakNodePtr parent;
    std::pmr::vector<NodePtr> children;
};

#endif // _NODE_H_