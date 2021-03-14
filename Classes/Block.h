#ifndef __Block_H__
#define __Block_H__

#include "cocos2d.h"
USING_NS_CC;

class CBlock : public Sprite
{
public:
	virtual bool init();
	virtual void update(float dlt);
	CREATE_FUNC(CBlock);
};

#endif