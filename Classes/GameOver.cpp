#include "GameOver.h"
#include "GamePlay.h"
#include "GameMenu.h"
#include "GlobalVar.h"
Scene* CGameOver::createScene(int nPlayerCount, float fTimer)
{
	Scene* pScene = Scene::create();
	CGameOver* pGO = CGameOver::create(nPlayerCount, fTimer);
	pScene->addChild(pGO);
	return pScene;
}

CGameOver* CGameOver::create(int nPlayerCount, float fTimer)
{
	CGameOver* pGO = new CGameOver();
	pGO->initWithData(nPlayerCount, fTimer);
	pGO->autorelease();
	return pGO;
}

void CGameOver::initGlobalVar()
{
	g_fPlayerGap = 0.06f;
	g_nBlockFrame = 80;
	g_nBlockMove = 2;
}

bool CGameOver::initWithData(int nPlayerCount, float fTimer)
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}
	m_nPlayerCount = nPlayerCount;
	m_fTimer = fTimer;
	Size visibleSize = Director::getInstance()->getVisibleSize();

	Label* pSurvivalTime = Label::createWithTTF(CCString::createWithFormat("Survival Time: %.2fs", m_fTimer)->getCString(), "fonts/JetBrainsMono-Bold-Italic.ttf", 32);
	pSurvivalTime->setColor(Color3B(0, 0, 0));
	pSurvivalTime->setPosition(visibleSize.width / 2, visibleSize.height*0.72);
	addChild(pSurvivalTime);

	Sprite* pTitle = Sprite::create("Image/GameOver.png");
	pTitle->setScale(0.8);
	pTitle->setPosition(visibleSize.width*0.5, visibleSize.height*0.65);
	addChild(pTitle);

	Sprite* pRetry = Sprite::create("Image/Retry.png");
	pRetry->setScale(0.65);
	pRetry->setPosition(visibleSize.width*0.5, visibleSize.height*0.53);
	addChild(pRetry);

	Sprite* pReturn = Sprite::create("Image/Return.png");
	pReturn->setScale(0.65);
	pReturn->setPosition(visibleSize.width*0.5, visibleSize.height*0.4);
	addChild(pReturn);
	
	m_pTouch = EventListenerTouchOneByOne::create();
	m_pTouch->onTouchBegan = [this, pRetry, pReturn](Touch* t, Event* e)
	{
		if (pRetry->getBoundingBox().containsPoint(t->getLocation()))
		{
			Director::getInstance()->getEventDispatcher()->removeEventListener(m_pTouch);
			Director::getInstance()->replaceScene(CGamePlay::createScene(m_nPlayerCount));
		}
		else if (pReturn->getBoundingBox().containsPoint(t->getLocation()))
		{
			Director::getInstance()->getEventDispatcher()->removeEventListener(m_pTouch);
			Director::getInstance()->replaceScene(CGameMenu::createScene());
			initGlobalVar();
		}
		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(m_pTouch, this);
	return true;
}