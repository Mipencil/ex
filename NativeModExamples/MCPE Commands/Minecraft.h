#pragma once
#include <memory>

class ServerCommandParser;
class Level;
class GameMode;
class NetEventCallback;
class Player;

class Minecraft{
	public:
		ServerCommandParser *getCommandParser(void);
		Level* getLevel(void);
		void hostMultiplayer(std::unique_ptr<Level,std::default_delete<Level>>,std::unique_ptr<GameMode,std::default_delete<GameMode>>,Player *,std::unique_ptr<NetEventCallback,std::default_delete<NetEventCallback>>,int,bool,bool,std::string,int,int,int);
};
