#ifndef __GameController_H__
#define __GameController_H__

#include "cocos2d.h"
#include "Edge.h"
#include "Block.h"
#include "Player.h"
USING_NS_CC;
class CGameController : public Scene  // 添加不同主角
{
public:
	virtual bool init(Layer* pLayer, float fPositionY, int nDiv);
	static CGameController* create(Layer* pLayer, float fPositionY, int nDiv);
	void onUpdate(float fDt);
	bool isHit(Vec2 point); // 判断是否有碰撞
	void onTouch();	 // 判断是否有点击
private:
	void resetFrame();
	void addBlock();
private:
	Layer* m_pLayer;
	float m_fPositionY;
	Size m_visibleSize;
	int curFrame; // 当前运行到的帧数
	int nextFrame; // 下一个要出现的帧数
	CEdge* m_pEdge;
	CPlayer* m_pPlayer;

	//int m_nDiv; // 几人玩，分几等分
	/*float m_fTimer;*/
	/*Label* pTimerLabel;*/
};

#endif