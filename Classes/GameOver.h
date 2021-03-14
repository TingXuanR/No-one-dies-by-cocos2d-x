#ifndef __GameOver_H__
#define __GameOver_H__

#include <cocos2d.h>

USING_NS_CC;

class CGameOver : public LayerColor 
{
public:
	virtual bool initWithData(int nPlayerCount, float fTimer);
	static Scene* createScene(int nPlayerCount, float fTimer);
	static CGameOver* create(int nPlayerCount, float fTimer);
private:
	Label* createLabel(std::string strName, std::string strFont, float fFontSize);
	void initGlobalVar();
private:
	int m_nPlayerCount;
	float m_fTimer;
	EventListenerTouchOneByOne* m_pTouch;
};


#endif