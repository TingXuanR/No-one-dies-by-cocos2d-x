#ifndef __Edge_H__
#define __Edge_H__

#include <iostream>
#include <cocos2d.h>

USING_NS_CC;

class CEdge :public Node {
public:
	virtual bool init(int nCount);
	static CEdge* create(int nCunt);
	//CREATE_FUNC(CEdge);
};

#endif 