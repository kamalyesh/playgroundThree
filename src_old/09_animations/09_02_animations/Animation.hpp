#ifndef Animation_hpp
#define Animation_hpp

#include <vector>

struct FrameData
{
    /* data */
    int id;                   // Texture id (retrieved from our texture allocator).
    int x;                    // x position of sprite in the texture.
    int y;                    // y position of sprite in the texture.
    int width;                // Width of sprite.
    int height;               // Height of sprite.
    float displayTimeSeconds; // How long to display the frame.
};

class Animation
{
public:
    Animation();
    void AddFrame(int textureID, int x, int y, int width, int height, float frameTimeFps);
    const FrameData *GetCurrentFrame() const;
    bool UpdateFrame(float deltaTimeFps);
    void Reset();

private:
    void IncrementFrame();
    std::vector<FrameData> frames;
    int currentFrameIndex;
    float currentFrameTimeFps;
};
#endif /* Animation_hpp */
