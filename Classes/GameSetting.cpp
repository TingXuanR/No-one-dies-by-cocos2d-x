#include "GameSetting.h"
#include "GlobalVar.h"
#include "GameMenu.h"
Scene* CGameSetting::createScene()
{
	Scene* pScene = Scene::create();
	CGameSetting* pGS = new CGameSetting();
	pGS->init();
	pGS->autorelease();
	pScene->addChild(pGS);
	return pScene;
}

bool CGameSetting::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
 
	Sprite* pEasy = Sprite::createWithSpriteFrameName("Easy.png");
	pEasy->setScale(0.8);
	pEasy->setPosition(visibleSize.width/2, visibleSize.height*0.7);
	addChild(pEasy);

	Sprite* pNormal = Sprite::createWithSpriteFrameName("Normal.png");
	pNormal->setScale(0.8);
	pNormal->setPosition(visibleSize.width / 2, visibleSize.height*0.55);
	addChild(pNormal);

	Sprite* pHard = Sprite::createWithSpriteFrameName("Hard.png");
	pHard->setScale(0.8);
	pHard->setPosition(visibleSize.width / 2, visibleSize.height*0.4);
	addChild(pHard);

	EventListenerTouchOneByOne* pTouch = EventListenerTouchOneByOne::create();
	pTouch->onTouchBegan = [pEasy, pNormal, pHard](Touch* t, Event* e){
		if (pEasy->getBoundingBox().containsPoint(t->getLocation()))
		{
			Director::getInstance()->replaceScene(CGameMenu::createScene());
		}
		else if (pNormal->getBoundingBox().containsPoint(t->getLocation()))
		{
			g_fPlayerGap = 0.05;
			g_nBlockFrame = 65;
			g_nBlockMove = 4;
			Director::getInstance()->replaceScene(CGameMenu::createScene());
		}
		else if (pHard->getBoundingBox().containsPoint(t->getLocation()))
		{
			g_fPlayerGap = 0.04;
			g_nBlockFrame = 50;
			g_nBlockMove = 6;
			Director::getInstance()->replaceScene(CGameMenu::createScene());
		}
		
		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(pTouch, this);

	return true;
}