#include "C_Animation.hpp"
#include "Object.hpp"

ComponentAnimation::ComponentAnimation(Object* owner) : Component(owner), currentAnimation(AnimationState::NONE, nullptr)
{
    
}

void ComponentAnimation::Awake()
{
    sprite = owner->GetComponent<ComponentSprite>();
}

void ComponentAnimation::Update(float deltaTime)
{
    if(currentAnimation.first != AnimationState::NONE)
    {
        bool newFrame = currentAnimation.second->UpdateFrame(deltaTime);
        
        if(newFrame)
        {
            const FrameData* data = currentAnimation.second->GetCurrentFrame();
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

const AnimationState& ComponentAnimation::GetAnimationState() const
{
    return currentAnimation.first;
}

void ComponentAnimation::SetAnimationDirection(FacingDirection direction)
{
    if(currentAnimation.first != AnimationState::NONE)
    {
        currentAnimation.second->SetDirection(direction);
    }
}