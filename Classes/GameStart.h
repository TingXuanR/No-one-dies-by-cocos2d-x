#ifndef __GameStart_H__
#define __GameStart_H__

#include <cocos2d.h>
USING_NS_CC;

class CGameStart : public LayerColor
{
public:
	virtual bool init();
	static Scene* createScene();
};

#endif