#include "Player.h"
#include "GlobalVar.h"
bool CPlayer::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	Size s = Size(67, 81);  // ���ͼƬ��С
	setContentSize(s);
	setPhysicsBody(PhysicsBody::createBox(s));
	getPhysicsBody()->setRotationEnable(false);
	getPhysicsBody()->setContactTestBitmask(1); // ������ײ���֪ͨ

	runAction(RepeatForever::create(createPlayerAnimation(g_fPlayerGap)));


	return true;
}

Animate* CPlayer::createPlayerAnimation(float fDelay) // ��д��STtring�����Ͳ���string
{
	Vector<SpriteFrame*> vec;

	char cFrameName[35] = {};
	for (int i = 1; i <= 5; i++)
	{
		sprintf(cFrameName, "Image/manInBlack0%d.png", i);  // ���������˶��ٶ�����ĳ��������᳤�󣬲����������߶�С���ϰ���
		SpriteFrame* pSprite = SpriteFrame::create(std::string(cFrameName), Rect(0, 0, 67, 81));
		if (pSprite)
		{
			vec.pushBack(pSprite);
		}
	}
	Animation* animation = Animation::createWithSpriteFrames(vec, fDelay);

	return Animate::create(animation);
}