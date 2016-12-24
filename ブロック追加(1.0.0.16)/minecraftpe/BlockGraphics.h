#pragma once

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

#include "TextureUVCoordinateSet.h"
#include "BlockShape.h"

class BlockSource;
class BlockPos;
class AABB;
class Random;
class Vec3;
class TextureAtlas;
class Color;
class Block;
namespace Json{
	class Value;
};


struct FullBlock;
struct BlockSoundType;

class BlockGraphics{
	public:
		//size:372
		char filler0[368];//4
	public:
		static void *SIZE_OFFSET;
		static std::unordered_map<std::string,BlockGraphics *> mBlockLookupMap;
		static BlockGraphics* mBlocks[256];
		static std::vector<std::unique_ptr<BlockGraphics>> mOwnedBlocks;
		static void *mTerrainTextureAtlas;
	public:
		BlockGraphics(std::string const&);
		virtual ~BlockGraphics();
		virtual void shouldRenderFace(BlockSource&, BlockPos const&, signed char, AABB const&) const;
		virtual void getIconYOffset() const;
		virtual void getColor(int) const;
		virtual void getColor(BlockSource&, BlockPos const&) const;
		virtual void getColorForParticle(BlockSource&, BlockPos const&, int) const;
		virtual void isSeasonTinted(BlockSource&, BlockPos const&) const;
		virtual void onGraphicsModeChanged(bool, bool);
		virtual void getRenderLayer(BlockSource&, BlockPos const&) const;
		virtual void getExtraRenderLayers();
		virtual void getVisualShape(BlockSource&, BlockPos const&, AABB&, bool);
		virtual void getVisualShape(unsigned char, AABB&, bool);
		virtual TextureUVCoordinateSet getCarriedTexture(signed char, int) const;
		virtual void animateTick(BlockSource&, BlockPos const&, Random&);
		virtual void randomlyModifyPosition(BlockPos const&, int&) const;
		virtual void randomlyModifyPosition(BlockPos const&) const;
		virtual void setVisualShape(AABB const&);
		virtual void setVisualShape(Vec3 const&, Vec3 const&);

		void getBlock(void);
		void getBlockShape(void);
		void getFaceTextureIsotropic(void);
		void getMapColor(FullBlock const&);
		void getMapColor(void);
		void getSoundType(void);
		void getTexture(signed char);
		void getTexture(signed char,int);
		void isAlphaTested(void);
		void isFullAndOpaque(void);
		void isTextureIsotropic(signed char);
		void reloadBlockUVs(TextureAtlas &);
		void setAllFacesIsotropic(void);
		void setBlockShape(BlockShape);
		void setCarriedTextureItem(std::string const&,std::string const&,std::string const&);
		void setCarriedTextureItem(std::string const&);
		void setMapColor(Color const&);
		void setSoundType(BlockSoundType);
		void setTextureAtlas(std::shared_ptr<TextureAtlas>);
		void setTextureIsotropic(unsigned int);
		void setTextureItem(std::string const&);
		void setTextureItem(std::string const&,std::string const&,std::string const&);
		void setTextureItem(std::string const&,std::string const&,std::string const&,std::string const&,std::string const&,std::string const&);
		void shouldRenderFace(BlockSource &,BlockPos const&,signed char,AABB const&);

		static void initBlocks(void);
		static void isFullAndOpaque(Block const&);
		static void getTextureItem(std::string const&);
		static void getTextureUVCoordinateSet(std::string const&,int);
		static void lookupByName(std::string const&,bool);
		static void setBlockShape(BlockGraphics&,Json::Value const&);
		static void setBrightnessGamma(BlockGraphics&,Json::Value const&);
		static void setCarriedTextures(BlockGraphics&,Json::Value const&);
		static void setSoundType(BlockGraphics&,Json::Value const&);
		static void setTextureIsotropic(BlockGraphics&,Json::Value const&);
		static void setTextures(BlockGraphics&,Json::Value const&);
		static void teardownBlocks(void);
};
