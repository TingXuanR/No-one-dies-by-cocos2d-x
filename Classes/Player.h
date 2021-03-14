#ifndef __Player_H__
#define __Player_H__


#include "cocos2d.h"

USING_NS_CC;

class CPlayer : public Sprite
{
public:
	virtual bool init();
	Animate* createPlayerAnimation(float fDelay);  // 通过每张图片的播放间隔来体现玩家的速度
	CREATE_FUNC(CPlayer);

};

#endif