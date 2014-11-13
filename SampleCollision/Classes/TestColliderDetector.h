#ifndef __SampleCollision__TestColliderDetector__
#define __SampleCollision__TestColliderDetector__

#include "cocos2d.h"
#include "cocos-ext.h"

#define SHOW_CONTOUE_DATA 1

#if SHOW_CONTOUE_DATA

#elif ENABLE_PHYSICS_BOX2D_DETECT
#include "GLES-Render.h"
#include "Box2D/Box2D.h"
#elif ENABLE_PHYSICS_CHIPMUNK_DETECT
#include "chipmunk.h"
#endif


#if SHOW_CONTOUE_DATA

class TestColliderDetector : public cocos2d::CCLayer
{
public:
	~TestColliderDetector();
    
	virtual void onEnter();
	virtual void onExit();
	virtual void update(float delta);
	virtual void draw();
    
	void onFrameEvent(cocos2d::extension::CCBone *bone, const char *evt, int originFrameIndex, int currentFrameIndex);

	cocos2d::extension::CCArmature *armature;
	cocos2d::extension::CCArmature *armature2;
	cocos2d::CCSprite* bullet;
	cocos2d::CCDrawNode* draw2;
	cocos2d::extension::CCBone* body;
};


#elif ENABLE_PHYSICS_BOX2D_DETECT

class ContactListener;

class TestColliderDetector : public cocos2d::CCLayer
{
public:
	~TestColliderDetector();
    
	virtual void onEnter();
	virtual void onExit();
	virtual void draw();
	virtual void update(float delta);
    
	void onFrameEvent(cocos2d::extension::CCBone *bone, const char *evt, int originFrameIndex, int currentFrameIndex);
    
	void initWorld();
    
    
	cocos2d::extension::CCArmature *armature;
	cocos2d::extension::CCArmature *armature2;
    
	cocos2d::extension::CCPhysicsSprite *bullet;
    
	b2World *world;
	ContactListener *listener;
	GLESDebugDraw *debugDraw;
};


#elif ENABLE_PHYSICS_CHIPMUNK_DETECT


class TestColliderDetector : public cocos2d::CCLayer
{
public:
	~TestColliderDetector();
    
	virtual void onEnter();
	virtual void onExit();
	virtual void update(float delta);
    
	void onFrameEvent(cocos2d::extension::CCBone *bone, const char *evt, int originFrameIndex, int currentFrameIndex);
    
	void initWorld();
    
    
	cocos2d::extension::CCArmature *armature;
	cocos2d::extension::CCArmature *armature2;
    
	cocos2d::extension::CCPhysicsSprite *bullet;
    
    
	cpSpace *space;
    
	static int beginHit(cpArbiter *arb, cpSpace *space, void *unused);
	static void endHit(cpArbiter *arb, cpSpace *space, void *unused);
    
	void destroyCPBody(cpBody *body);
};
#endif


#endif /* defined(__SampleCollision__TestColliderDetector__) */
