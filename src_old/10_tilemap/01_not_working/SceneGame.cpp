#include "SceneGame.hpp"

SceneGame::SceneGame(WorkingDirectory& workingDir, ResourceAllocator<sf::Texture>& textureAllocator) : workingDir(workingDir), textureAllocator(textureAllocator), mapParser(textureAllocator) { }

void SceneGame::OnCreate()
{
    std::shared_ptr<Object> player = std::make_shared<Object>();
    
    auto sprite = player->AddComponent<ComponentSprite>();
    sprite->SetTextureAllocator(&textureAllocator);
    
    auto movement = player->AddComponent<ComponentKeyboardMovement>();
    movement->SetInput(&input);
    
    auto animation = player->AddComponent<ComponentAnimation>();

    int vikingTextureID = textureAllocator.Add(workingDir.Resources() + "texture/Viking.png");

    const int frameWidth = 165;
    const int frameHeight = 145;

    // We pass in the animations direction when creating a new animation.
    // The character in the sprites faces right so we set that
    // as the initial direction.
    std::shared_ptr<Animation> idleAnimation = std::make_shared<Animation>(FacingDirection::RIGHT);
    const float idleAnimFrameSeconds = 0.2f;
    idleAnimation->AddFrame(vikingTextureID, 600, 0, frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(vikingTextureID, 800, 0, frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(vikingTextureID, 0, 145, frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(vikingTextureID, 200, 145, frameWidth, frameHeight, idleAnimFrameSeconds);
    animation->AddAnimation(AnimationState::IDLE, idleAnimation);


    // WALK animation
    std::shared_ptr<Animation> walkAnimation = std::make_shared<Animation>(FacingDirection::RIGHT);
    const float walkAnimFrameSeconds = 0.2f;
    walkAnimation->AddFrame(vikingTextureID, 600, 290, frameWidth, frameHeight, walkAnimFrameSeconds);
    walkAnimation->AddFrame(vikingTextureID, 800, 290, frameWidth, frameHeight, walkAnimFrameSeconds);
    walkAnimation->AddFrame(vikingTextureID, 0, 435, frameWidth, frameHeight, walkAnimFrameSeconds);
    walkAnimation->AddFrame(vikingTextureID, 200, 435, frameWidth, frameHeight, walkAnimFrameSeconds);
    walkAnimation->AddFrame(vikingTextureID, 400, 435, frameWidth, frameHeight, walkAnimFrameSeconds);
    animation->AddAnimation(AnimationState::IDLE, walkAnimation);
    
    objects.Add(player);

    // You will need to play around with this offset until it fits 
	// the level in at your chosen resolution. This worls for 1920 * 1080.
    // In future we will remove this hardcoded offset when we 
	// look at allowing the player to change resolutions.
    sf::Vector2i mapOffset(-100, 128);
    std::vector<std::shared_ptr<Object>> levelTiles = mapParser.Parse(workingDir.Resources() + "tilemap/Test Map 1.tmx", mapOffset);

    objects.Add(levelTiles);
}

void SceneGame::OnDestroy()
{
    
}

void SceneGame::ProcessInput()
{
    input.Update();
}

void SceneGame::Update(float deltaTime)
{
    objects.ProcessRemovals();
    objects.ProcessNewObjects();
    
    objects.Update(deltaTime);
}

void SceneGame::LateUpdate(float deltaTime)
{
    objects.LateUpdate(deltaTime);
}

void SceneGame::Draw(Window& window)
{
    objects.Draw(window);
}
