#ifndef __Player_H__
#define __Player_H__


#include "cocos2d.h"

USING_NS_CC;

class CPlayer : public Sprite
{
public:
	virtual bool init();
	Animate* createPlayerAnimation(float fDelay);  // ͨ��ÿ��ͼƬ�Ĳ��ż����������ҵ��ٶ�
	CREATE_FUNC(CPlayer);

};

#endif