#include "EPlayer.h"
#include "Core/Application/ApplicationShortcuts.h"
#include "Simulation/ECS/ECS.h"
#include "Simulation/Features/Score/CPlayerScore.h"
#include "Simulation/Features/Shooting/CCannon.h"


EPlayer::EPlayer(const ConfigPlayer& configPlayer)
{
    Claim<CPlayerControllableTag>();

    Claim<CAnimation>(getConfig().textures.Find([&configPlayer](const ConfigTexture& texture) {
        return texture.name == configPlayer.imageName;
    }));

    Claim<CPosition>(configPlayer.startPosition);
    Claim<CPhysics>().SetMember(&CPhysics::mass, *configPlayer.mass);

    Claim<CPlayerScore>();
    Claim<CCannon>();
}
