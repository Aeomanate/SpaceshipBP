#ifndef SPACESHIPBP_ECS_H
#define SPACESHIPBP_ECS_H

#include "Simulation/ECS/Features/Movable/CPosition.h"
#include "Simulation/ECS/Features/Movable/CPhysics.h"
#include "Simulation/ECS/Features/Movable/CRequestMovement.h"
#include "Simulation/ECS/Features/Movable/SEntityMover.h"

#include "Simulation/ECS/Features/CollisionDetection/SCollisionDetector.h"

#include "Simulation/ECS/Features/Visual/CSceneElement.h"
#include "Simulation/ECS/Features/Visual/SVisualAttenuation.h"
#include "Simulation/ECS/Features/Visual/SSpriteAnimator.h"
#include "Simulation/ECS/Features/Visual/SEntityDrawer.h"

#include "Simulation/ECS/Features/LifetimeControl/ESpawnerContainer.h"
#include "Simulation/ECS/Features/LifetimeControl/SSpawner.h"
#include "Simulation/ECS/Features/LifetimeControl/SDespawner.h"

#include "Simulation/ECS/Features/Input/CPlayerControllableTag.h"
#include "Simulation/ECS/Features/Input/CQueueMouseMoves.h"
#include "Simulation/ECS/Features/Input/CQueueMouseClicks.h"
#include "Simulation/ECS/Features/Input/CQueuePlayerMoveDirections.h"
#include "Simulation/ECS/Features/Input/EInputContainer.h"
#include "Simulation/ECS/Features/Input/SInputInjector.h"
#include "Simulation/ECS/Features/Input/SInputCleaner.h"

#include "Simulation/ECS/Features/Levels/ELevelState.h"
#include "Simulation/ECS/Features/Levels/SLevelStateForwarder.h"

#endif //SPACESHIPBP_ECS_H
