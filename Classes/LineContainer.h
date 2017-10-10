#ifndef __LINECONTAINER_H__
#define __LINECONTAINER_H__

#include "cocos2d.h"

USING_NS_CC;

class LineContainer : public CCNode{
public:
	CC_SYNTHESIZE(CCPoint,_ballPoint,BallPoint);
	CC_SYNTHESIZE(CCPoint,_cuePoint,CuePoint);
	CC_SYNTHESIZE(bool,_drawing,Drawing);

	LineContainer();
	//static LineContainer *create();
	CREATE_FUNC(LineContainer);
//	virtual void draw() final;
    virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
//    virtual void draw() final;

private:
	int _dash;
	int _dashSpace;
	CCSize _screenSize;
};


#endif