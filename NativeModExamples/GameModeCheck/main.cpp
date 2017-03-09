#include <dlfcn.h>
#include <jni.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <android/log.h>

#include "Substrate.h"
#include "message/Message.h"

#include "minecraftpe/gamemode/GameMode.h"
#include "minecraftpe/client/gui/GuiData.h"

void (*_GuiData_tick)(GuiData *);
void GuiData_tick(GuiData *self){
	Message::guiData=self;
}

void (*_GameMode_attack)(GameMode *,Player &,Entity &);
void GameMode_attack(GameMode *self,Player &_player,Entity &_entity){
	Message::clientMessage("attack");
	_GameMode_attack(self,_player,_entity);
}

void (*_GameMode_buildBlock)(GameMode *,Player &,BlockPos &,signed char);
void GameMode_buildBlock(GameMode *self,Player &_player,BlockPos &_blockPos,signed char _char){
	Message::clientMessage("buildBlock");
	_GameMode_buildBlock(self,_player,_blockPos,_char);
}

void (*_GameMode_continueBuildBlock)(GameMode *,Player &,BlockPos &,signed char);
void GameMode_continueBuildBlock(GameMode *self,Player &_player,BlockPos &_blockPos,signed char _char){
	Message::clientMessage("_continueBuildBlock");
	_GameMode_continueBuildBlock(self,_player,_blockPos,_char);
}

void (*_GameMode_continueDestroyBlock)(GameMode *,Player &,BlockPos &,signed char);
void GameMode_continueDestroyBlock(GameMode *self,Player &_player,BlockPos &_blockPos,signed char _char){
	Message::clientMessage("continueDestroyBlock");
	_GameMode_continueDestroyBlock(self,_player,_blockPos,_char);
}

bool (*_GameMode_destroyBlock)(GameMode *,Player &,BlockPos &,signed char);
bool GameMode_destroyBlock(GameMode *self,Player &_player,BlockPos &_blockPos,signed char _char){
	Message::clientMessage("destroyBlock");
	return _GameMode_destroyBlock(self,_player,_blockPos,_char);
}

void (*_GameMode_startBuildBlock)(GameMode *,Player &,BlockPos &,signed char);
void GameMode_startBuildBlock(GameMode *self,Player &_player,BlockPos &_blockPos,signed char _char){
	Message::clientMessage("startBuildBlock");
	_GameMode_startBuildBlock(self,_player,_blockPos,_char);
}

void (*_GameMode_startDestroyBlock)(GameMode *,Player &,BlockPos &,signed char);
void GameMode_startDestroyBlock(GameMode *self,Player &_player,BlockPos &_blockPos,signed char _char){
	Message::clientMessage("startDestroyBlock");
	_GameMode_startDestroyBlock(self,_player,_blockPos,_char);
}

void (*_GameMode_stopBuildBlock)(GameMode *,Player &);
void GameMode_stopBuildBlock(GameMode *self,Player &_player){
	Message::clientMessage("stopBuildBlock");
	_GameMode_stopBuildBlock(self,_player);
}

void (*_GameMode_stopDestroyBlock)(GameMode *,Player &);
void GameMode_stopDestroyBlock(GameMode *self,Player &_player){
	Message::clientMessage("stopDestroyBlock");
	_GameMode_stopDestroyBlock(self,_player);
}

bool (*_GameMode_useItem)(GameMode *,Player &,ItemInstance &);
bool GameMode_useItem(GameMode *self,Player &_player,ItemInstance &_itemInstance){
	Message::clientMessage("useItem");
	return _GameMode_useItem(self,_player,_itemInstance);
}

bool (*_GameMode_useItemOn)(GameMode *,Player &,ItemInstance *,BlockPos const&,signed char,Vec3 const&);
bool GameMode_useItemOn(GameMode *self,Player &_player,ItemInstance *_itemInstance,BlockPos const &_blockPos,signed char _char,Vec3 const &_vec3){
	Message::clientMessage("useItemOn");
	return _GameMode_useItemOn(self,_player,_itemInstance,_blockPos,_char,_vec3);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved){
	MSHookFunction((void*)&GuiData::tick,(void*)&GuiData_tick,(void**)&_GuiData_tick);
	MSHookFunction((void*)&GameMode::attack,(void*)&GameMode_attack,(void**)&_GameMode_attack);
	MSHookFunction((void*)&GameMode::buildBlock,(void*)&GameMode_buildBlock,(void**)&_GameMode_buildBlock);
	MSHookFunction((void*)&GameMode::continueBuildBlock,(void*)&GameMode_continueBuildBlock,(void**)&_GameMode_continueBuildBlock);
	MSHookFunction((void*)&GameMode::continueDestroyBlock,(void*)&GameMode_continueDestroyBlock,(void**)&_GameMode_continueDestroyBlock);
	MSHookFunction((void*)&GameMode::destroyBlock,(void*)&GameMode_destroyBlock,(void**)&_GameMode_destroyBlock);
	MSHookFunction((void*)&GameMode::startBuildBlock,(void*)&GameMode_startBuildBlock,(void**)&_GameMode_startBuildBlock);
	MSHookFunction((void*)&GameMode::startDestroyBlock,(void*)&GameMode_startDestroyBlock,(void**)&_GameMode_startDestroyBlock);
	//MSHookFunction((void*)&GameMode::stopBuildBlock,(void*)&GameMode_stopBuildBlock,(void**)&_GameMode_stopBuildBlock);
	MSHookFunction((void*)&GameMode::stopDestroyBlock,(void*)&GameMode_stopDestroyBlock,(void**)&_GameMode_stopDestroyBlock);
	MSHookFunction((void*)&GameMode::useItem,(void*)&GameMode_useItem,(void**)&_GameMode_useItem);
	MSHookFunction((void*)&GameMode::useItemOn,(void*)&GameMode_useItemOn,(void**)&_GameMode_useItemOn);
	return JNI_VERSION_1_2;
}
