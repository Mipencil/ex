#pragma once
#include <string>

#include "../minecraftpe/client/gui/GuiData.h"

class Message{
	public:
		static GuiData* guiData;
	public:
		static void clientMessage(std::string const&);
};
