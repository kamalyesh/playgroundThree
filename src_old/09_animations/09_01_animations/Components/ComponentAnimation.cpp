#include "ComponentAnimation.hpp"
#include <iostream>
#define P(s) std::cout<<s<<std::endl;
ComponentAnimation::ComponentAnimation(Object *object) : Component(owner), currentAnimation(AnimationState::NONE, nullptr)
{
}

void ComponentAnimation::Awake()
{
    P("ComponentAnimation::Awake")
    try
    {
        /* code */
        P("sprite = owner->GetComponent<ComponentSprite>()")
        sprite = owner->GetComponent<ComponentSprite>();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void ComponentAnimation::Update(float deltaTimeFps)
{
    if (currentAnimation.first == AnimationState::NONE)
    {
        bool newFrame = currentAnimation.second->UpdateFrame(deltaTimeFps);
        if (newFrame)
        {
            const FrameData *data = currentAnimation.second->GetCurrentFrame();
            sprite->Load(data->id);
            sprite->SetTextureRect(data->x, data->y, data->width, data->height);
        }
    }
}

void ComponentAnimation::AddAnimation(AnimationState state, std::shared_ptr<Animation> animation)
{
    auto inserted = animations.insert(std::make_pair(state, animation));
    if (currentAnimation.first == AnimationState::NONE)
    {
        SetAnimationState(state);
    }
}

void ComponentAnimation::SetAnimationState(AnimationState state)
{
    // We only set an animation of it is not already
    // our current animation.

    if (currentAnimation.first == state)
    {
        return;
    }

    auto animation = animations.find(state);
    if (animation != animations.end())
    {
        currentAnimation.first = animation->first;
        currentAnimation.second = animation->second;
        currentAnimation.second->Reset();
    }
}

const AnimationState &ComponentAnimation::GetAnimationState() const
{
    // Returns out current animation state. We can use this
    // to compare the objects current state to a desired state.
    return currentAnimation.first;
}