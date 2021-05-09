#include "Animation.hpp"

Animation::Animation() : frames(0), currentFrameIndex(0), currentFrameTimeFps(0.f)
{
}

void Animation::AddFrame(int textureID, int x, int y, int width, int height, float frameTimeFps)
{
    FrameData data;
    data.id = textureID;
    data.x = x;
    data.y = y;
    data.width = width;
    data.height = height;
    data.displayTimeSeconds = frameTimeFps;

    frames.push_back(data);
}

const FrameData *Animation::GetCurrentFrame() const
{
    if (frames.size() > 0)
    {
        return &frames[currentFrameIndex];
    }

    return nullptr;
}

bool Animation::UpdateFrame(float deltaTimeFps)
{
    if (frames.size() > 0)
    {
        currentFrameTimeFps += deltaTimeFps;

        if (currentFrameTimeFps >= frames[currentFrameIndex].displayTimeSeconds)
        {
            currentFrameTimeFps = 0.f;
            IncrementFrame();
            return true;
        }
    }

    return false;
}

void Animation::IncrementFrame()
{
    currentFrameIndex = (currentFrameIndex + 1) % frames.size();
}

void Animation::Reset()
{
    currentFrameIndex = 0;
    currentFrameTimeFps = 0.f;
}
