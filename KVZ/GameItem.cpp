#include "GameItem.h"

namespace KVZ
{

	GameItem::GameItem()
	{
		itemType = -1;
	}

	GameItem::GameItem(int type)
	{
		itemType = type;
	}

	GameItem::~GameItem()
	{
	}

	int GameItem::getItemType() const
	{
		return itemType;
	}

}