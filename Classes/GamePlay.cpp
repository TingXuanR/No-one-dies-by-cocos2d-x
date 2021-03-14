#include "GamePlay.h"
#include "GameOver.h"

void CGamePlay::setCount(int nCount)
{
	m_nPlayerCount = nCount;
}
CGamePlay* CGamePlay::create(int nCount)
{
	CGamePlay* pGC = new CGamePlay();
	pGC->setCount(nCount);
	pGC->init();
	pGC->autorelease();
	return pGC;
}
Scene* CGamePlay::createScene(int nCount)
{
	Scene* pScene = Scene::createWithPhysics();
	//pScene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	pScene->getPhysicsWorld()->setGravity(Vec2(0, -980));
	pScene->addChild(CGamePlay::create(nCount));

	return pScene;
}

void CGamePlay::update(float fDt)
{
	m_fTimer += fDt;
	m_pTimerLabel->setString(CCString::createWithFormat("Timer: %.2f", m_fTimer)->getCString()); 
	for (auto gc : m_vecGC)  // 执行每一个游戏控制器的方法
	{

		gc->onUpdate(fDt);
	}
}

bool CGamePlay::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))  // 不能使用Color3B
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// 创建游戏场景
	int nOffsetY = 30;
	for (int i = 0; i < m_nPlayerCount; i++)
	{
		m_vecGC.pushBack(CGameController::create(this, nOffsetY, m_nPlayerCount));
		nOffsetY += visibleSize.height/m_nPlayerCount;
	}

	scheduleUpdate();

	m_fTimer = 0.0;
	// 添加计时器
	m_pTimerLabel = Label::createWithTTF(CCString::createWithFormat("Timer: %.2f", m_fTimer)->getCString(), "fonts/JetBrainsMono-Bold-Italic.ttf", 26.0);
	m_pTimerLabel->setColor(Color3B(0, 0, 0));
	m_pTimerLabel->setPosition(visibleSize.width * 0.75, visibleSize.height * 0.95);
	addChild(m_pTimerLabel);

	// 检测点击
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = [this](Touch* t, Event* e){

		for (auto gc : m_vecGC)
		{
			if (gc->isHit(t->getLocation()))
			{
				gc->onTouch();
				break;
			}
		}

		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

	// 测试碰
	auto crashListener = EventListenerPhysicsContact::create();
	crashListener->onContactBegin = [this](PhysicsContact &contact)
	{
		this->unscheduleUpdate();
		Director::getInstance()->replaceScene(CGameOver::createScene(m_nPlayerCount, m_fTimer));

		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(crashListener, this);


	return true;
}