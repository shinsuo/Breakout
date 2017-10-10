#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

#include "cocos2d.h"

#include "Box2D/Box2D.h"
#include "Ball.h"
#include "Cue.h"
#include "LineContainer.h"
#include "GLES_Render.h"

enum{
	kBackground,
	kMiddleground,
	kForeground
};

enum{
	kGameIntro,
	kGamePlay,
	kGameOver
};

class GameLayer : public cocos2d::CCLayer
{
public:
	~GameLayer();
	GameLayer();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

	CC_SYNTHESIZE(b2World*, _world,World);
	CC_SYNTHESIZE(bool,_canShoot,CanShoot);

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
	void initPhysics();

	virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags);
    virtual void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);
    virtual void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);
    virtual void onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event);


    // implement the "static node()" method manually
    CREATE_FUNC(GameLayer);

	void update(float dt);
	void ticktock(float dt);
private:
	GLESDebugDraw *m_debugDraw;
	b2ContactListener *_collisionListener;

	CCTouch *_touch;
	CCArray *_balls;
	CCArray *_pockets;
	CCSpriteBatchNode *_gameBatchNode;
	CCSprite *_intro;
	CCSprite *_gameOver;
	CCLabelBMFont *_timer;

	LineContainer *_lineContainer;

	CCPoint _cueStartPoint;
	CCSize _screenSize;
	bool _running;
	bool _usingCue;

	float _pullBack;
	float _cueAngle;
	int _gameState;

	int _ballsInPlay;
	int _time;

	
	Ball *_player;
	Cue *_cue;

	void placeCue(CCPoint position);
	void resetGame(void);
};

#endif  // __HELLOWORLD_SCENE_H__