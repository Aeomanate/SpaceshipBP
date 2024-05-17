#include "EBackground.h"
#include "Simulation/ECS/ECS.h"
#include "Core/Application/ObjectsAggregator/GetterConfig.h"

EBackground::EBackground()
: ECS::Entity("Background")
{
    Claim<CSceneElement>()
        .SetMember(&CSceneElement::sprite, getConfig().resources.textures.background)
        .SetMember(&CSceneElement::order, CSceneElement::ZOrder::UNDEFINED);
}
