#include "EPlayer.h"
#include "Simulation/ECS/BasicFeatures/PlayerControllable/CPlayerControllableTag.h"
#include "Simulation/ECS/BasicFeatures/PlayerControllable/CMovementDirectionQueue.h"
#include "Simulation/ECS/BasicFeatures/Movable/CMass.h"
#include "Simulation/ECS/BasicFeatures/Movable/CPosition.h"
#include "Simulation/ECS/BasicFeatures/Movable/CSpeed.h"
#include "Simulation/ECS/BasicFeatures/Movable/CAppliedForces.h"
#include "Simulation/Features/Score/CPlayerScore.h"
#include "Simulation/Features/Shooting/CCannon.h"

EPlayer::EPlayer()
{
    ClaimComponent<CPlayerControllableTag>();
    ClaimComponent<CMovementDirectionQueue>();

    ClaimComponent<CMass>();
    ClaimComponent<CPosition>();
    ClaimComponent<CSpeed>();
    ClaimComponent<CAppliedForces>();

    ClaimComponent<CPlayerScore>();
    ClaimComponent<CCannon>();

}
