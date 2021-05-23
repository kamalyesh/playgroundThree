#ifndef ComponentAnimation_hpp
#define ComponentAnimation_hpp

#include "Component.hpp"
#include "Animation.hpp"
#include "C_Sprite.hpp"

enum class AnimationState
{
    NONE,
    IDLE,
    WALK
};

class ComponentAnimation : public Component
{
public:
    ComponentAnimation(Object* owner);
    
    void Awake() override;
    
    void Update(float deltaTime) override;
    
    void AddAnimation(AnimationState state, std::shared_ptr<Animation> animation);
    void SetAnimationState(AnimationState state);
    void SetAnimationDirection(FacingDirection direction);
    const AnimationState& GetAnimationState() const;
    
private:
    std::shared_ptr<ComponentSprite> sprite;
    std::map<AnimationState, std::shared_ptr<Animation>> animations;
    std::pair<AnimationState, std::shared_ptr<Animation>> currentAnimation;
};

#endif /* ComponentAnimation_hpp */
