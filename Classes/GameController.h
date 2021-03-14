#ifndef __GameController_H__
#define __GameController_H__

#include "cocos2d.h"
#include "Edge.h"
#include "Block.h"
#include "Player.h"
USING_NS_CC;
class CGameController : public Scene  // ��Ӳ�ͬ����
{
public:
	virtual bool init(Layer* pLayer, float fPositionY, int nDiv);
	static CGameController* create(Layer* pLayer, float fPositionY, int nDiv);
	void onUpdate(float fDt);
	bool isHit(Vec2 point); // �ж��Ƿ�����ײ
	void onTouch();	 // �ж��Ƿ��е��
private:
	void resetFrame();
	void addBlock();
private:
	Layer* m_pLayer;
	float m_fPositionY;
	Size m_visibleSize;
	int curFrame; // ��ǰ���е���֡��
	int nextFrame; // ��һ��Ҫ���ֵ�֡��
	CEdge* m_pEdge;
	CPlayer* m_pPlayer;

	//int m_nDiv; // �����棬�ּ��ȷ�
	/*float m_fTimer;*/
	/*Label* pTimerLabel;*/
};

#endif