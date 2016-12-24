#pragma once

#include <string>
#include <memory>
#include <unordered_map>

#include "TextureUVCoordinateSet.h"
#include "CreativeItemCategory.h"

class ItemInstance;
class Block;
class Level;
class Player;
class BlockSource;
class Container;
class Vec3;
class Mob;
class IDataInput;
class IDataOutput;
class Entity;
class ResourcePackManager;
class TextureAtlas;

namespace Json{
	class Value;
};

struct UseAnimation;
struct BlockID;

class Item{
	public:
		class Tier{
			public:
				static Tier DIAMOND;
				static Tier GOLD;
				static Tier IRON;
				static Tier STONE;
				static Tier WOOD;
			public:
				//size:20
				int tier1;//0
				int damage;//4
				float destroySpeed;//8
				int tier2;//12
				int enchantData;//16
			public:
				ItemInstance &getTierItem(void) const;
		};
	public:
		//size:108
		//void **vtable;//0
		char filler0[104];//4
	public:
		Item(std::string const&, short);
		virtual ~Item();
		virtual void setIcon(std::string const&, int);
		virtual void setIcon(TextureUVCoordinateSet const&);
		virtual void setMaxStackSize(unsigned char);
		virtual void setCategory(CreativeItemCategory);
		virtual void setStackedByData(bool);
		virtual void setMaxDamage(int);
		virtual void setHandEquipped();
		virtual void setUseAnimation(UseAnimation);
		virtual void setMaxUseDuration(int);
		virtual void setRequiresWorldBuilder(bool);
		virtual void setExplodable(bool);
		virtual void setIsGlint(bool);
		virtual void setShouldDespawn(bool);
		virtual void getBlockShape() const;
		virtual void canBeDepleted();
		virtual void canDestroySpecial(Block const*) const;
		virtual void getLevelDataForAuxValue(int) const;
		virtual void isStackedByData() const;
		virtual void getMaxDamage();
		virtual void getAttackDamage();
		virtual void isHandEquipped() const;
		virtual void isArmor() const;
		virtual void isDye() const;
		virtual void isGlint(ItemInstance const*) const;
		virtual void isThrowable() const;
		virtual void canDestroyInCreative() const;
		virtual void isLiquidClipItem(int) const;
		virtual void requiresInteract() const;
		virtual void appendFormattedHovertext(ItemInstance const&, Level&, std::string&, bool) const;
		virtual void isValidRepairItem(ItemInstance const&, ItemInstance const&);
		virtual void getEnchantSlot() const;
		virtual void getEnchantValue() const;
		virtual void isComplex() const;
		virtual void isValidAuxValue(int) const;
		virtual void getDamageChance(int)const;
		virtual void uniqueAuxValues() const;
		virtual void getColor(ItemInstance const&) const;
		virtual void use(ItemInstance&, Player&);
		virtual void useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
		virtual void dispense(BlockSource&, Container&, int, Vec3 const&, signed char);
		virtual void useTimeDepleted(ItemInstance*, Level*, Player*);
		virtual void releaseUsing(ItemInstance*, Player*, int);
		virtual void getDestroySpeed(ItemInstance*, Block*);
		virtual void hurtEnemy(ItemInstance*, Mob*, Mob*);
		virtual void interactEnemy(ItemInstance*, Mob*, Player*);
		virtual void mineBlock(ItemInstance*, BlockID, int, int, int, Mob*);
		virtual std::string buildDescriptionName(ItemInstance const&) const;
		virtual void buildEffectDescriptionName(ItemInstance const&) const;
		virtual void readUserData(ItemInstance*, IDataInput&) const;
		virtual void writeUserData(ItemInstance const*, IDataOutput&) const;
		virtual void getMaxStackSize(ItemInstance const*);
		virtual void inventoryTick(ItemInstance&, Level&, Entity&, int, bool);
		virtual void onCraftedBy(ItemInstance&, Level&, Player&);
		virtual void getCooldownType() const;
		virtual void getCooldownTime()const;
		virtual void getInteractText(Player const&) const;
		virtual void getAnimationFrameFor(Mob&) const;
		virtual void isEmissive(int) const;
		virtual TextureUVCoordinateSet& getIcon(int, int, bool) const;
		virtual void getIconYOffset() const;
		virtual void isMirroredArt() const;

		void _textMatch(std::string const&, std::string const&, bool);
		void destroySpeedBonus(ItemInstance const*);
		void getTextureItem(std::string const&);
		void initClient(Json::Value &);
		void initServer(Json::Value &);
		void initServerData(ResourcePackManager &);
		void setIsMirroredArt(bool);
		void setTextureAtlas(std::shared_ptr<TextureAtlas>);
		void teardownItems(void);

		static void addBlockItems(void);
		static void addCreativeItem(Block const*,short);
		static void addCreativeItem(Item*,short);
		static void addCreativeItem(ItemInstance const&);
		static void addCreativeItem(short,short);
		static void initCreativeItems(void);
		static void initClientData(void);
		static void registerItems(void);
		static void getTextureUVCoordinateSet(std::string const&,int);
		static Item *lookupByName(std::string const&,bool);
	public:
		static std::shared_ptr<TextureAtlas> mItemTextureAtlas;
		static Item *mItems[512];
		static std::unordered_map<std::string,std::unique_ptr<Item>> mItemLookupMap;
		//static std::vector<Item*> *mCreativeList;
		//static Random *mRandom;

		static Item *mApple;
		static Item *mApple_enchanted;
		static Item *mApple_gold;
		static Item *mArrow;
		static Item *mBed;
		static Item *mBeef_cooked;
		static Item *mBeef_raw;
		static Item *mBeetroot;
		static Item *mBeetrootSoup;
		static Item *mBlazePowder;
		static Item *mBlazeRod;
		static Item *mBoat;
		static Item *mBone;
		static Item *mBook;
		static Item *mBoots_chain;
		static Item *mBoots_cloth;
		static Item *mBoots_diamond;
		static Item *mBoots_gold;
		static Item *mBoots_iron;
		static Item *mBow;
		static Item *mBowl;
		static Item *mBread;
		static Item *mBrewing_stand;
		static Item *mBrick;
		static Item *mBucket;
		static Item *mCake;
		static Item *mCamera;
		static Item *mCarrot;
		static Item *mCarrotOnAStick;
		static Item *mCauldron;
		static Item *mChalkboard;
		static Item *mChestMinecart;
		static Item *mChestplate_chain;
		static Item *mChestplate_cloth;
		static Item *mChestplate_diamond;
		static Item *mChestplate_gold;
		static Item *mChestplate_iron;
		static Item *mChicken_cooked;
		static Item *mChicken_raw;
		static Item *mClay;
		static Item *mClock;
		static Item *mCoal;
		static Item *mComparator;
		static Item *mCompass;
		static Item *mCookie;
		static Item *mDiamond;
		static Item *mDiamondHorseArmor;
		static Item *mDoor_acacia;
		static Item *mDoor_birch;
		static Item *mDoor_darkoak;
		static Item *mDoor_iron;
		static Item *mDoor_jungle;
		static Item *mDoor_spruce;
		static Item *mDoor_wood;
		static Item *mDye_powder;
		static Item *mEgg;
		static Item *mEmerald;
		static Item *mEmptyMap;
		static Item *mEnchanted_book;
		static Item *mEnderpearl;
		static Item *mExperiencePotionItem;
		static Item *mFeather;
		static Item *mFermented_spider_eye;
		static Item *mFilledMap;
		static Item *mFireCharge;
		static Item *mFish_cooked_cod;
		static Item *mFish_cooked_salmon;
		static Item *mFish_raw_clownfish;
		static Item *mFish_raw_cod;
		static Item *mFish_raw_pufferfish;
		static Item *mFish_raw_salmon;
		static Item *mFishingRod;
		static Item *mFlint;
		static Item *mFlintAndSteel;
		static Item *mFlowerPot;
		static Item *mGhast_tear;
		static Item *mGlass_bottle;
		static Item *mGoldHorseArmor;
		static Item *mGoldIngot;
		static Item *mGold_nugget;
		static Item *mGoldenCarrot;
		static Item *mHatchet_diamond;
		static Item *mHatchet_gold;
		static Item *mHatchet_iron;
		static Item *mHatchet_stone;
		static Item *mHatchet_wood;
		static Item *mHelmet_chain;
		static Item *mHelmet_cloth;
		static Item *mHelmet_diamond;
		static Item *mHelmet_gold;
		static Item *mHelmet_iron;
		static Item *mHoe_diamond;
		static Item *mHoe_gold;
		static Item *mHoe_iron;
		static Item *mHoe_stone;
		static Item *mHoe_wood;
		static Item *mHopper;
		static Item *mHopperMinecart;
		static Item *mIronHorseArmor;
		static Item *mIronIngot;
		static Item *mItemFrame;
		static Item *mLead;
		static Item *mLeather;
		static Item *mLeatherHorseArmor;
		static Item *mLeggings_chain;
		static Item *mLeggings_cloth;
		static Item *mLeggings_diamond;
		static Item *mLeggings_gold;
		static Item *mLeggings_iron;
		static Item *mMagma_cream;
		static Item *mMelon;
		static Item *mMinecart;
		static Item *mMobPlacer;
		static Item *mMushroomStew;
		static Item *mMutton_cooked;
		static Item *mMutton_raw;
		static Item *mNameTag;
		static Item *mNetherQuartz;
		static Item *mNetherStar;
		static Item *mNether_wart;
		static Item *mNetherbrick;
		static Item *mPainting;
		static Item *mPaper;
		static Item *mPickAxe_diamond;
		static Item *mPickAxe_gold;
		static Item *mPickAxe_iron;
		static Item *mPickAxe_stone;
		static Item *mPickAxe_wood;
		static Item *mPoisonous_potato;
		static Item *mPorkChop_cooked;
		static Item *mPorkChop_raw;
		static Item *mPortfolioBook;
		static Item *mPotato;
		static Item *mPotatoBaked;
		static Item *mPotion;
		static Item *mPrismarineCrystals;
		static Item *mPrismarineShard;
		static Item *mPumpkinPie;
		static Item *mRabbitCooked;
		static Item *mRabbitFoot;
		static Item *mRabbitHide;
		static Item *mRabbitRaw;
		static Item *mRabbitStew;
		static Item *mRedStone;
		static Item *mReeds;
		static Item *mRepeater;
		static Item *mRotten_flesh;
		static Item *mSaddle;
		static Item *mSeeds_beetroot;
		static Item *mSeeds_melon;
		static Item *mSeeds_pumpkin;
		static Item *mSeeds_wheat;
		static Item *mShears;
		static Item *mShovel_diamond;
		static Item *mShovel_gold;
		static Item *mShovel_iron;
		static Item *mShovel_stone;
		static Item *mShovel_wood;
		static Item *mSign;
		static Item *mSkull;
		static Item *mSlimeBall;
		static Item *mSnowBall;
		static Item *mSpeckled_melon;
		static Item *mSpider_eye;
		static Item *mSplash_potion;
		static Item *mStick;
		static Item *mString;
		static Item *mSugar;
		static Item *mSulphur;
		static Item *mSword_diamond;
		static Item *mSword_gold;
		static Item *mSword_iron;
		static Item *mSword_stone;
		static Item *mSword_wood;
		static Item *mTNTMinecart;
		static Item *mWheat;
		static Item *mYellowDust;
};
