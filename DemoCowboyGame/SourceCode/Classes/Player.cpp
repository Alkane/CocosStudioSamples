//
//  Player.cpp
//  CowboyScene
//
//  Created by NiTe Luo on 10/17/13.
//
//

#include "Player.h"


Player::Player(CCNode* playerNode)
:CCObject()
{
    this->playerNode = playerNode;
    CCComRender* comRender = static_cast<CCComRender*>(playerNode->getComponent("CCArmature"));
	CCArmature *animationNode = static_cast<CCArmature*>(comRender->getNode());
    this->animation = animationNode->getAnimation();
    this->animation->setMovementEventCallFunc(this, movementEvent_selector(Player::onAnimationEvent));
    currentState = IDLE;
    newState = IDLE;
    lockState = false;
}

void Player::setDirection(int newDirection)
{
    direction = newDirection;
    playerNode->setScaleX(direction * fabs(playerNode->getScaleX()));
}

void Player::update(float dt)
{
    if (currentState == newState || isLockState())
    {
        updateMovement();
    }
    else
    {
        currentState = newState;
        updateAnimation();
    }
}

void Player::updateMovement()
{
    CCPoint oldPos = playerNode->getPosition();
    if (currentState == WALK)
    {
        playerNode->setPosition(oldPos.x + -direction * WALK_SPEED, oldPos.y);
    }
}

void Player::updateAnimation()
{
    switch (currentState)
    {
        case IDLE:
            animation->play("stand");
            break;
        case SHOOT:
            animation->play("stand_fire");
            break;
        case WALK:
            animation->play("walk");
            break;
        case GRENADE:
            animation->play("grenade");
            lockState = true;
            break;
        default:
            break;
    }
}

bool Player::isLockState()
{
    return lockState;
}

void Player::onAnimationEvent(cocos2d::extension::CCArmature *pArmature, cocos2d::extension::MovementEventType eventType, const char *animationID)
{
    if (eventType == LOOP_COMPLETE)
    {
        if (strcmp(animationID, "grenade") == 0)
        {
            lockState = false;
            newState = IDLE;
        }
    }
}
