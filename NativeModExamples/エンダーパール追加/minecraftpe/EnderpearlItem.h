#pragma once

#include "Item.h"

class EnderpearlItem:public Item{
	public:
		char filler1[24];
	public:
		EnderpearlItem(std::string const&,int);
		virtual ~EnderpearlItem();
		virtual void use(ItemInstance &,Player &);
};
