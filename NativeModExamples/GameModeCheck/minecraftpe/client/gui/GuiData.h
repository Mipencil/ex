#pragma once

#include <string>
#include <vector>
class GuiData{
	public:
		void addMessage(std::string const&,std::string const&,int,bool);
		void displayClientMessage(std::string const&);
		void displayChatMessage(std::string const&,std::string const&);
		void displaySystemMessage(std::string const&);
		void displayLocalizableMessage(std::string const&,std::vector<std::string,std::allocator<std::string>> const&);
		void showTipMessage(std::string const&);
		void showPopupNotice(std::string const&,std::string const&);
		void postError(int);
		void tick(void);
};