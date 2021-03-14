#include "GameStart.h"
#include "GamePlay.h"
#include "GameMenu.h"
Scene* CGameStart::createScene()
{
	Scene* pScene = Scene::createWithPhysics();
	CGameStart* pGS = new CGameStart();
	pGS->init();
	pScene->addChild(pGS);
	return pScene;
}

bool CGameStart::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();

	Sprite* pTitle = Sprite::createWithSpriteFrameName("GameTitle.png");
	pTitle->setPosition(visibleSize.width*0.55, visibleSize.height*0.82);
	addChild(pTitle);

	Sprite* pLogo = Sprite::create();
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
	MenuItemSprite* pOnePlayer = MenuItemSprite::create(Sprite::createWithSpriteFrameName("one.png"),
		Sprite::createWithSpriteFrameName("oneSelected.png"),
		[](Ref* sender){
		Director::getInstance()->replaceScene(CGamePlay::createScene(1));
	}
	);
	/*	auto p = ParticleGalaxy::create();
	p->setPosition(pOnePlayer->getPosition());*/
	pOnePlayer->setPosition(0, visibleSize.height*0.7);
	MenuItems.pushBack(pOnePlayer);

	//Sprite* pTwoPlayers = Sprite::create("Image/two.png");
	MenuItemSprite* pTwoPlayers = MenuItemSprite::create(Sprite::createWithSpriteFrameName("two.png"),
		Sprite::createWithSpriteFrameName("twoSelected.png"),
		[](Ref* sender){
		Director::getInstance()->replaceScene(CGamePlay::createScene(2));
	}
	);
	pTwoPlayers->setPosition(0, pOnePlayer->getPositionY() - pOnePlayer->getContentSize().height - 10);
	MenuItems.pushBack(pTwoPlayers);

	MenuItemSprite* pThreePlayers = MenuItemSprite::create(Sprite::createWithSpriteFrameName("three.png"),
		Sprite::createWithSpriteFrameName("threeSelected.png"),
		[](Ref* sender){
		Director::getInstance()->replaceScene(CGamePlay::createScene(3));
	}
	);
	pThreePlayers->setPosition(0, pTwoPlayers->getPositionY() - pTwoPlayers->getContentSize().height - 10);
	MenuItems.pushBack(pThreePlayers);

	//Sprite* pExit = Sprite::create("Image/eit.png");
	MenuItemSprite* pExit = MenuItemSprite::create(Sprite::createWithSpriteFrameName("eit.png"),
		Sprite::createWithSpriteFrameName("eitSelected.png"),
		[](Ref* sender){
		Director::getInstance()->replaceScene(CGameMenu::createScene());
	}
	);
	pExit->setPosition(0, pThreePlayers->getPositionY() - pThreePlayers->getContentSize().height - 10);
	MenuItems.pushBack(pExit);

	auto menu = Menu::createWithArray(MenuItems);
	menu->setPosition(menu->getContentSize().width / 2, 0);
	this->addChild(menu, 1);

	return true;
}