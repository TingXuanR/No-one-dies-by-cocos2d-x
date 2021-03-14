#include "Player.h"
#include "GlobalVar.h"
bool CPlayer::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	Size s = Size(67, 81);  // 玩家图片大小
	setContentSize(s);
	setPhysicsBody(PhysicsBody::createBox(s));
	getPhysicsBody()->setRotationEnable(false);
	getPhysicsBody()->setContactTestBitmask(1); // 设置碰撞检测通知

	runAction(RepeatForever::create(createPlayerAnimation(g_fPlayerGap)));


	return true;
}

Animate* CPlayer::createPlayerAnimation(float fDelay) // 大写的STtring，类型不是string
{
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
	Animation* animation = Animation::createWithSpriteFrames(vec, fDelay);

	return Animate::create(animation);
}