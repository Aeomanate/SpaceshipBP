#include "EBackground.h"
#include "Simulation/ECS/Features/Visual/CAnimation.h"
#include "Core/Application/ApplicationShortcuts.h"

EBackground::EBackground()
{
    Claim<CAnimation>(getConfig().textures.background);
}
