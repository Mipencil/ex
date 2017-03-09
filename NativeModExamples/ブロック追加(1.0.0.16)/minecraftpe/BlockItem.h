#pragma once

#include "Item.h"

class BlockItem:public Item{
	public:
		//size:112
		char filler1[4];//108
	public:
		BlockItem(std::string const&,int);
		virtual ~BlockItem();
		virtual void useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
		virtual std::string buildDescriptionName(ItemInstance const&) const;
		virtual void isEmissive(int) const;
		virtual TextureUVCoordinateSet& getIcon(int, int, bool) const;
		virtual void getIconYOffset() const;		
};
