#include "EPlayer.h"
#include "Core/Application/ApplicationShortcuts.h"
#include "Simulation/ECS/ECS.h"
#include "Simulation/Features/Score/CPlayerScore.h"
#include "Simulation/Features/Shooting/CCannon.h"


EPlayer::EPlayer(const ConfigPlayer& configPlayer)
: ECS::Entity("Player")
{
    Claim<CPlayerControllableTag>();

    Claim<CSceneElement>()
        .SetMember(&CSceneElement::sprite, getConfig().textures.Find([&configPlayer](const ConfigTexture& texture) {
            return texture.name == configPlayer.imageName;
        }))
        .SetMember(&CSceneElement::order, CSceneElement::ZOrder::PLAYER);

    Claim<CPosition>(*configPlayer.startPosition);
    Claim<CPhysics>().SetMember(&CPhysics::mass, *configPlayer.mass);

    Claim<CPlayerScore>();
    Claim<CCannon>();
}
