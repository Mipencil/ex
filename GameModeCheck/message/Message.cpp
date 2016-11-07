#include <stdlib.h>
#include "Message.h"

GuiData *Message::guiData=NULL;

void Message::clientMessage(std::string const& message){
	Message::guiData->displayClientMessage(message);
}
