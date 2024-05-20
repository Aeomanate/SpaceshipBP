#ifndef SPACESHIPBP_ECS_H
#define SPACESHIPBP_ECS_H

#include "Features/Movable/CPosition.h"
#include "Features/Movable/CRotation.h"
#include "Features/Movable/CPhysics.h"
#include "Features/Movable/CRequestMovement.h"
#include "Features/Movable/SEntityMover.h"

#include "Features/CollisionDetection/SCollisionDetector.h"

#include "Features/Visual/CSceneElement.h"
#include "Features/Visual/SVisualAttenuation.h"
#include "Features/Visual/SSpriteAnimator.h"
#include "Features/Visual/SEntityDrawer.h"

#include "Features/LifetimeControl/ESpawnerContainer.h"
#include "Features/LifetimeControl/SSpawner.h"
#include "Features/LifetimeControl/SDespawner.h"

#include "Features/Input/CPlayerControllableTag.h"
#include "Features/Input/CInputMousePositions.h"
#include "Features/Input/CInputMouseClicks.h"
#include "Features/Input/CInputMoveDirections.h"
#include "Features/Input/EInputContainer.h"
#include "Features/Input/SInputInjector.h"
#include "Features/Input/SInputCleaner.h"

#include "Features/Levels/ELevelState.h"
#include "Features/Levels/CLevelState.h"
#include "Features/Levels/SLevelStateForwarder.h"

#include "Features/Debug/CText.h"
#include "Features/Debug/EDebugText.h"
#include "Features/Debug/SDebugInfo.h"

#endif //SPACESHIPBP_ECS_H
