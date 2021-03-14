#include "GameController.h"
#include "GlobalVar.h"

CGameController* CGameController::create(Layer* pLayer, float fPositionY, int nDiv)
{
	CGameController* pGC = new CGameController();
	pGC->init(pLayer, fPositionY, nDiv);
	return pGC;
}

bool CGameController::init(Layer* pLayer, float fPositionY, int nDiv)
{
	// ��ʼ��
	m_pLayer = pLayer;
	m_fPositionY = fPositionY;
	curFrame = 0;
	nextFrame = 0;
	m_visibleSize = Director::getInstance()->getVisibleSize();

	// ��ӱ߽�
	m_pEdge = CEdge::create(nDiv);
	m_pEdge->setPosition(0, m_fPositionY);
	m_pLayer->addChild(m_pEdge);

	// ������
	m_pPlayer = CPlayer::create();
	m_pPlayer->setPosition(m_visibleSize.width/4, m_pPlayer->getContentSize().height + m_fPositionY);
	m_pLayer->addChild(m_pPlayer);

	// ��ӵذ�
	Sprite* pGround = Sprite::create();
	pGround->setTextureRect(Rect(0, 0, m_visibleSize.width, 3));
	pGround->setColor(Color3B(0, 0, 0));
	pGround->setPosition(m_visibleSize.width/2, m_fPositionY);
	m_pLayer->addChild(pGround);

	// ��Ӽ�ʱ��
	/*pTimerLabel = Label::create();
	pTimerLabel->setColor(Color3B(0, 0, 0));
	pTimerLabel->setSystemFontSize(28);
	pTimerLabel->setPosition(m_visibleSize.width * 0.85, m_visibleSize.height * 0.95);
	m_pLayer->addChild(pTimerLabel);*/

	return true;
}

void CGameController::addBlock()
{
	CBlock* pBlock = CBlock::create();
	m_pLayer->addChild(pBlock);
	pBlock->setPositionY(pBlock->getContentSize().height / 2 + m_fPositionY);
}

void CGameController::onUpdate(float fDt)
{
	curFrame++;
	/*m_fTimer += fDt;
	pTimerLabel->setString(CCString::createWithFormat("Timer: %.2f", m_fTimer)->getCString());*/
	if (curFrame >= nextFrame)
	{
		resetFrame();
		addBlock();
	}
}

void CGameController::resetFrame()
{
	curFrame = 0;
	nextFrame = rand() % 120 + g_nBlockFrame; // �������֡�����ɡ�����1.5�� 
}

bool CGameController::isHit(Vec2 point)
{
	return m_pEdge->getBoundingBox().containsPoint(point);
}

void CGameController::onTouch()
{
	// avoid һ�����Ļ��Ҿ�����
	if (m_pPlayer->getPositionY() < m_fPositionY + m_pPlayer->getContentSize().height / 2 + 3) 
	// +3��Ϊ��avoid���.���Ե�������: getPositionY: 71.78, getContentSize().height: 81.00
	{
		m_pPlayer->getPhysicsBody()->setVelocity(Vec2(0, 630)); // �����ٶ�
	}
	
}