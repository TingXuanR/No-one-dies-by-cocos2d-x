#ifndef __GamePlay_H__
#define __GamePlay_H__

#include <cocos2d.h>
#include "GameController.h"
USING_NS_CC;

class CGamePlay : public LayerColor
{
public:
	virtual  bool init();
	static Scene* createScene(int nCount);
	static CGamePlay* create(int nCount);
	void setCount(int nCount);

	void update(float fDt);
private:
	Vector<CGameController*> m_vecGC;
	int m_nPlayerCount;
	float m_fTimer; 
	Label* m_pTimerLabel;
};

#endif