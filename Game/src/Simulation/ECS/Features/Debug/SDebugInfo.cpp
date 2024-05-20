#include "SDebugInfo.h"

#include <format>
#include "Simulation/ECS/ECS.h"
#include "Core/Application/ObjectsAggregator/GetterConfig.h"
#include "Utility/Math/Vectors.h"

void SDebugInfo::Update(float dt)
{
    const auto& mousePosQueue = REF(CInputMousePositions::TryGetFirstDataPtr()).value;
    if(mousePosQueue.empty())
    { return; }

    auto [mouse_x, mouse_y] = mousePosQueue.front();

    float playerRotateAngle = 0;
    for (auto [player, rotation]: CRotation::All() | CPlayerControllableTag::Filter())
    {
        playerRotateAngle = *rotation;
    }

    REF(CText::TryGetFirstDataPtr()).value.setString(std::format(
        "Mouse pos: [{:4}; {:4}]"
        "\nRotate angle: {:6.2f}",
        mouse_x, mouse_y,
        playerRotateAngle
    ));
}
