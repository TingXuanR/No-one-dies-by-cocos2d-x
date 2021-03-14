#include "Edge.h"

CEdge* CEdge::create(int nCount)
{
	CEdge* pE = new CEdge();
	pE->init(nCount);
	pE->autorelease();
	return pE;
}

bool CEdge::init(int nCount){

	if (!Node::init())
	{
		return true;
	}
	Size edgeSize = Director::getInstance()->getVisibleSize();
	edgeSize.height /= nCount;
	setContentSize(edgeSize);
	setPhysicsBody(PhysicsBody::createEdgeBox(edgeSize, PhysicsMaterial(0.1f, 0.1f, 0.1f))); 
	//PhysicsMaterial���ܶȣ�Ħ��ϵ��������ϵ����

	return true;
}