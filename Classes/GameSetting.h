#ifndef __GameSetting_H__
#define __GameSetting_H__

#include <cocos2d.h>
USING_NS_CC;

class CGameSetting : public LayerColor
{
public:
	virtual bool init();
	static Scene* createScene();
};
#endif