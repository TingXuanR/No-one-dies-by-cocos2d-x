#ifndef __GameMenu_H__
#define __GameMenu_H__


#include "cocos2d.h"

USING_NS_CC;

class CGameMenu : public LayerColor
{
public:
	virtual bool init();
	static Scene* createScene();
};

#endif