#ifndef __MINIPOOL_CUE__
#define __MINIPOOL_CUE__

#include "b2Sprite.h"

class Cue : public b2Sprite{
public:
	~Cue();
	Cue(GameLayer *game);
	static Cue* create(GameLayer *game);
private:
	void initCue();
};


#endif