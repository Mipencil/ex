#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "Material.h"
#include "CreativeItemCategory.h"

class BlockSource;
class BlockPos;
class Random;
class AABB;
class Entity;
class Container;
class Vec3;
class Player;
class Mob;
class Color;
class ItemInstance;

struct BlockID;
struct BlockSupportType;
struct BlockProperty;
struct Brightness;
struct EntityType;

class Block{
	public:
		static Block *mBlocks[256];
		static std::unordered_map<std::string,Block *> mBlockLookupMap;
		static std::vector<std::unique_ptr<Block>> mOwnedBlocks;
	public:
		//size:120
		char filler0[8];//4
		std::string name;//12
		char filler1[104];//16
	public:
		Block(std::string const&,int,Material const&);
		virtual ~Block();
		virtual void tick(BlockSource&, BlockPos const&, Random&);
		virtual void getCollisionShape(AABB&, BlockSource&, BlockPos const&, Entity*);
		virtual void isObstructingChests(BlockSource&, BlockPos const&);
		virtual void randomlyModifyPosition(BlockPos const&, int&) const;
		virtual void randomlyModifyPosition(BlockPos const&) const;
		virtual void addAABBs(BlockSource&, BlockPos const&, AABB const*, std::vector<AABB, std::allocator<AABB> >&);
		virtual void getAABB(BlockSource&, BlockPos const&, AABB&, int, bool, int);
		virtual void addCollisionShapes(BlockSource&, BlockPos const&, AABB const*, std::vector<AABB, std::allocator<AABB> >&, Entity*);
		virtual void canProvideSupport(BlockSource&, BlockPos const&, signed char, BlockSupportType);
		virtual void isInfiniburnBlock(int)const;
		virtual void isCropBlock() const;
		virtual void isContainerBlock() const;
		virtual void isCraftingBlock() const;
		virtual void isInteractiveBlock() const;
		virtual void isWaterBlocking() const;
		virtual void isHurtableBlock() const;
		virtual void isFenceBlock() const;
		virtual void isStairBlock() const;
		virtual void isRailBlock() const;
		virtual void canHurtAndBreakItem() const;
		virtual void isRedstoneBlock() const;
		virtual void isSignalSource() const;
		virtual void getDirectSignal(BlockSource&, BlockPos const&, int);
		virtual void waterSpreadCausesSpawn() const;
		virtual void handleRain(BlockSource&, BlockPos const&, float) const;
		virtual void getThickness() const;
		virtual void checkIsPathable(Entity&, BlockPos const&, BlockPos const&);
		virtual void dispense(BlockSource&, Container&, int, Vec3 const&, signed char);
		virtual void onPlace(BlockSource&, BlockPos const&);
		virtual void onRemove(BlockSource&, BlockPos const&);
		virtual void onExploded(BlockSource&, BlockPos const&, Entity*);
		virtual void onStepOn(Entity&, BlockPos const&);
		virtual void onFallOn(BlockSource&, BlockPos const&, Entity*, float);
		virtual void onRedstoneUpdate(BlockSource&, BlockPos const&, int, bool);
		virtual void onMove(BlockSource&, BlockPos const&, BlockPos const&);
		virtual void detachesOnPistonMove(BlockSource&, BlockPos const&);
		virtual void onLoaded(BlockSource&, BlockPos const&);
		virtual void getRedstoneProperty(BlockSource&, BlockPos const&);
		virtual void updateEntityAfterFallOn(Entity&);
		virtual void onFertilized(BlockSource&, BlockPos const&, Player*);
		virtual void mayConsumeFertilizer(BlockSource&);
		virtual void mayPick();
		virtual void mayPick(BlockSource&, int, bool);
		virtual void mayPlace(BlockSource&, BlockPos const&, signed char);
		virtual void mayPlace(BlockSource&, BlockPos const&);
		virtual void mayPlaceOn(Block const&);
		virtual void tryToPlace(BlockSource&, BlockPos const&, unsigned char);
		virtual void breaksFallingBlocks(int)const;
		virtual void destroy(BlockSource&, BlockPos const&, int, Entity*);
		virtual void playerWillDestroy(Player&, BlockPos const&, int);
		virtual void neighborChanged(BlockSource&, BlockPos const&, BlockPos const&);
		virtual void getSecondPart(BlockSource&, BlockPos const&, BlockPos&);
		virtual void getResource(Random&, int, int);
		virtual void getResourceCount(Random&, int, int);
		virtual void asItemInstance(BlockSource&, BlockPos const&, int) const;
		virtual void spawnResources(BlockSource&, BlockPos const&, int, float, int);
		virtual void spawnBurnResources(BlockSource&, float, float, float);
		virtual void getExplosionResistance(Entity*) const;
		virtual void clip(BlockSource&, BlockPos const&, Vec3 const&, Vec3 const&, bool, int);
		virtual void use(Player&, BlockPos const&);
		virtual void getPlacementDataValue(Mob&, BlockPos const&, signed char, Vec3 const&, int);
		virtual void calcVariant(BlockSource&, BlockPos const&, unsigned char) const;
		virtual void isAttachedTo(BlockSource&, BlockPos const&, BlockPos&);
		virtual void attack(Player*, BlockPos const&);
		virtual void handleEntityInside(BlockSource&, BlockPos const&, Entity*, Vec3&);
		virtual void entityInside(BlockSource&, BlockPos const&, Entity&);
		virtual void playerDestroy(Player*, BlockPos const&, int);
		virtual void canSurvive(BlockSource&, BlockPos const&);
		virtual void getExperienceDrop(Random&) const;
		virtual void canBeBuiltOver(BlockSource&, BlockPos const&) const;
		virtual void triggerEvent(BlockSource&, BlockPos const&, int, int);
		virtual void getMobToSpawn(BlockSource&, BlockPos const&) const;
		virtual void getMapColor(BlockSource&, BlockPos const&) const;
		virtual void getMapColor() const;
		virtual void shouldStopFalling(Entity&);
		virtual void calcGroundFriction(Mob&, BlockPos const&) const;
		virtual void canHaveExtraData() const;
		virtual void hasComparatorSignal();
		virtual void getComparatorSignal(BlockSource&, BlockPos const&, signed char, int);
		virtual void shouldRenderFace(BlockSource&, BlockPos const&, signed char, AABB const&) const;
		virtual void getIconYOffset() const;
		virtual void buildDescriptionName(unsigned char) const;
		virtual void getColor(int) const;
		virtual void getColor(BlockSource&, BlockPos const&) const;
		virtual void getColor(BlockSource&, BlockPos const&, unsigned char) const;
		virtual void getColorForParticle(BlockSource&, BlockPos const&, int) const;
		virtual void isSeasonTinted(BlockSource&, BlockPos const&) const;
		virtual void onGraphicsModeChanged(bool, bool, bool);
		virtual void getRenderLayer(BlockSource&, BlockPos const&) const;
		virtual void getExtraRenderLayers();
		virtual void getVisualShape(BlockSource&, BlockPos const&, AABB&, bool);
		virtual void getVisualShape(unsigned char, AABB&, bool);
		virtual void getVariant(int) const;
		virtual void getMappedFace(signed char, int) const;
		virtual void animateTick(BlockSource&, BlockPos const&, Random&);
		virtual void init();
		virtual void canBeSilkTouched() const;
		virtual void getSilkTouchItemInstance(unsigned char);
		virtual void setVisualShape(AABB const&);
		virtual void setVisualShape(Vec3 const&, Vec3 const&);
		virtual void setLightBlock(Brightness);
		virtual void setLightEmission(float);
		virtual void setExplodeable(float);
		virtual void setDestroyTime(float);
		virtual void setFriction(float);
		virtual void setBlockProperty(BlockProperty);
		virtual void setTicking(bool);
		virtual void setMapColor(Color const&);
		virtual void addProperty(BlockProperty);
		virtual void getSpawnResourcesAuxValue(unsigned char);

		void addAABB(AABB const&,AABB const*,std::vector<AABB,std::allocator<AABB>> &);
		void canInstatick(void);
		void canSlide(void);
		void getBlockEntityType(void);
		void getCreativeCategory(void);
		void getDescriptionId(void);
		void getDestroySpeed(void);
		void getFriction(void);
		void getGravity(void);
		void getMaterial(void);
		void getLightEmission(BlockID);
		void getProperties(void);
		void getShadeBrightness(void);
		void getTypeToSpawn(BlockSource &,EntityType,BlockPos const&);
		void hasBlockEntity(void);
		void hasProperty(BlockProperty);
		void isAlphaTested(void);
		void isHeavy(void);
		void isSolid(void);
		void isSolidBlockingBlock(void);
		void isType(Block const*);
		void isUnbreakable(void);
		void popResource(BlockSource &,BlockPos const&,ItemInstance const&);
		void setCategory(CreativeItemCategory);
		void setNameId(std::string const&);
		void setSolid(bool);
		void transformToValidBlockId(BlockID);
		void transformToValidBlockId(BlockID,BlockPos const&);

		static void initBlocks(void);
		static void lookupByName(std::string const&,bool);
		static void teardownBlocks(void);
};
