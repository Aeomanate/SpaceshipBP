#include "EDebugText.h"
#include "Core/Application/ObjectsAggregator/GetterFontProvider.h"

EDebugText::EDebugText()
: ECS::Entity("EDebugText")
{
    Claim<CText>().value.setFont(getFontsCache().GetResource(getConfig().resources.fonts.basicFont));
}
