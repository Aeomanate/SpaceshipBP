#include "SDebugInfo.h"

#include <format>
#include "Simulation/ECS/ECS.h"

void SDebugInfo::Update(float dt)
{
    const auto& mousePosQueue = REF(CInputMousePositions::TryGetFirstDataPtr()).value;
    if(mousePosQueue.empty())
    { return; }

    auto [mouse_x, mouse_y] = mousePosQueue.front();

    REF(CText::TryGetFirstDataPtr()).value.setString(std::format(
        "Mouse pos: [{:4}; {:4}]",
        mouse_x, mouse_y

        ));
}
