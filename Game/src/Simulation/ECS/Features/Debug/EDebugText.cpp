#include "EDebugText.h"
#include "Core/Application/ObjectsAggregator/GetterFontProvider.h"
#include "Simulation/ECS/ECS.h"

EDebugText::EDebugText()
: ECS::Entity("EDebugText")
{
    Claim<CText>().value.setFont(getFontsCache().GetResource(getConfig().resources.fonts.basicFont));
    Claim<CPosition>();
}
