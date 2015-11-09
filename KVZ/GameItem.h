#pragma once


namespace KVZ
{

	class GameItem
	{

		/*
		 * @brief id of item type
		 */
		int itemType;

	public:

		GameItem();

		GameItem(int type);

		virtual ~GameItem();

		/**
		 * @brief return item type
		 */
		int getItemType() const;

	};

}

