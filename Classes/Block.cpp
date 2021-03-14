#include "Block.h"
#include "GlobalVar.h"
bool CBlock::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	Size blockSize = Size(rand() % 20 + 5, rand() % 45 + 10);
	Size visibleSize = Director::getInstance()->getVisibleSize();

	setContentSize(blockSize);
	setTextureRect(Rect(0, 0, blockSize.width, blockSize.height));
	setColor(Color3B(0, 0, 0));
	setPositionX(visibleSize.width);

	setPhysicsBody(PhysicsBody::createBox(blockSize));
	// 设置碰撞检测
	getPhysicsBody()->setContactTestBitmask(1);
	
	// 不能移动
	getPhysicsBody()->setDynamic(false);

	scheduleUpdate();
	
	return true;
}

void CBlock::update(float dlt)
{
	setPositionX(getPositionX() - g_nBlockMove);
	if (getPositionX() < 0)
	{
		unscheduleUpdate();
		removeFromParent();
	}
}