#ifndef C_Animation_hpp
#define C_Animation_hpp

#include "Component.hpp"
#include "Object.hpp"
#include "Animation.hpp"
#include "ComponentSprite.hpp"

enum class AnimationState
{
    NONE,
    IDLE,
    WALK
};

class ComponentAnimation : public Component
{

public:
    ComponentAnimation(Object *owner);

    void Awake() override;
    void Update(float deltaTimeFps) override;

    // Add animation to object. We need its state as well
    // so that we can switch to it.
    void AddAnimation(AnimationState state, std::shared_ptr<Animation> animation);

    // Set current animation states.
    void SetAnimationState(AnimationState state);

    // Returns current animation state.
    const AnimationState &GetAnimationState() const;

private:
    std::shared_ptr<ComponentSprite> sprite;
    std::map<AnimationState, std::shared_ptr<Animation>> animations;

    // We store a reference to the current animation so we
    // can quickly update and draw it.
    std::pair<AnimationState, std::shared_ptr<Animation>> currentAnimation;
};

#endif /* C_Animation_hpp */
