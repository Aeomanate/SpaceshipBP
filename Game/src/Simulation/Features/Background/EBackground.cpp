#include "EBackground.h"
#include "Simulation/ECS/Features/Visual/CSceneElement.h"
#include "Core/Application/ApplicationShortcuts.h"

EBackground::EBackground()
: ECS::Entity("Background")
{
    Claim<CSceneElement>()
        .SetMember(&CSceneElement::sprite, getConfig().textures.background)
        .SetMember(&CSceneElement::order, CSceneElement::ZOrder::UNDEFINED);
}
