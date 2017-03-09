#pragma once

#include <functional>

class BlockPos;
class Entity;
class InputMode;
class ItemInstance;
class Level;
class PacketSender;
class Player;
class SoundPlayer;
class Vec3;
class Vibration;

class GameMode{
	public:
		GameMode(PacketSender &,Level &,SoundPlayer &,Vibration &);
		void _creativeDestroyBlock(Player &,BlockPos,signed char);
		void _destroyBlockInternal(Player &,BlockPos,signed char);
		void _releaseUsingItemInternal(Player &);
		virtual void attack(Player &,Entity &);
		virtual void buildBlock(Player &,BlockPos,signed char);
		virtual void continueBuildBlock(Player &,BlockPos,signed char);
		virtual void continueDestroyBlock(Player &,BlockPos,signed char);
		virtual bool destroyBlock(Player &,BlockPos,signed char);
		void getDestroyProgress(void);
		void getHitProgress(float);
		void getOldDestroyProgress(void);
		virtual void getPickRange(Player *,InputMode const&,bool);
		virtual void interact(Player &,Entity &);
		virtual void isInTrialMode(void);
		virtual void registerUpsellScreenCallback(std::function<void (bool)>);
		virtual void releaseUsingItem(Player &);
		virtual void setTrialMode(bool);
		virtual void startBuildBlock(Player &,BlockPos,signed char);
		virtual void startDestroyBlock(Player &,BlockPos,signed char);
		virtual void stopBuildBlock(Player &);
		virtual void stopDestroyBlock(Player &);
		virtual void tick(void);
		void toggleLongPickRange(void);
		virtual bool useItem(Player &,ItemInstance &);
		virtual bool useItemOn(Player &,ItemInstance *,BlockPos const&,signed char,Vec3 const&);
		virtual ~GameMode();
};
