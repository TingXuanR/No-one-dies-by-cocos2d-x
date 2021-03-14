#include "GameMenu.h"
#include "GameSetting.h"
#include "GameStart.h"
Scene* CGameMenu::createScene()
{
	Scene* pScene = Scene::createWithPhysics();
	CGameMenu* pGM = new CGameMenu();
	pGM->init();
	pScene->addChild(pGM);
	return pScene;
}

bool CGameMenu::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();

	SpriteFrameCache* pCache = SpriteFrameCache::getInstance();
	pCache->addSpriteFramesWithFile("Image/pics.plist");

	Sprite* pTitle = Sprite::createWithSpriteFrameName("GameTitle.png");
	pTitle->setPosition(visibleSize.width*0.55, visibleSize.height*0.82);
	addChild(pTitle);

	Sprite* pLogo = Sprite::create("Image/manInBlack01.png");
	pLogo->setPosition(visibleSize.width*0.3, visibleSize.height*0.9);
	addChild(pLogo);
	Vector<SpriteFrame*> vec;
	char cFrameName[35] = {};
	for (int i = 1; i <= 5; i++)
	{
		sprintf(cFrameName, "Image/manInBlack0%d.png", i);  // 设置他吃了多少东西或某样东西后会长大，不惧怕体积或高度小的障碍物
		SpriteFrame* pSprite = SpriteFrame::create(std::string(cFrameName), Rect(0, 0, 67, 81));
		if (pSprite)
		{
			vec.pushBack(pSprite);
		}
	}
	Animation* animation = Animation::createWithSpriteFrames(vec, 0.05f);
	pLogo->runAction(RepeatForever::create(Animate::create(animation)));
	
	

	Sprite* pLine = Sprite::createWithSpriteFrameName("line.png");
	pLine->setPosition(visibleSize.width*0.55, visibleSize.height*0.78);
	addChild(pLine);

	Vector<MenuItem*> MenuItems;

	MenuItemSprite* pStart = MenuItemSprite::create(Sprite::createWithSpriteFrameName("GameStart.png"),
		Sprite::createWithSpriteFrameName("GameStartSelected.png"),
		[](Ref* sender){
		Director::getInstance()->replaceScene(CGameStart::createScene());
	}
	);
	pStart->setPosition(0, visibleSize.height*0.7);
	MenuItems.pushBack(pStart);

	MenuItemSprite* pSetting = MenuItemSprite::create(Sprite::createWithSpriteFrameName("GameSetting.png"),
		Sprite::createWithSpriteFrameName("GameSettingSelected.png"),
		[](Ref* sender){
		Director::getInstance()->replaceScene(CGameSetting::createScene());
	}
	);
	pSetting->setPosition(0, pStart->getPositionY() - pStart->getContentSize().height - 10);
	MenuItems.pushBack(pSetting);

	MenuItemSprite* pExit = MenuItemSprite::create(Sprite::createWithSpriteFrameName("GameExit.png"),
		Sprite::createWithSpriteFrameName("GameExitSelected.png"),
		[](Ref* sender){
		exit(0);
	}
	);
	pExit->setPosition(0, pSetting->getPositionY() - pSetting->getContentSize().height - 10);
	MenuItems.pushBack(pExit);

	auto menu = Menu::createWithArray(MenuItems);
	menu->setPosition(menu->getContentSize().width / 2, 0);
	this->addChild(menu, 1);


	return true;
}