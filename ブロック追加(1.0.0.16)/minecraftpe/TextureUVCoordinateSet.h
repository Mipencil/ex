#pragma once

struct ResourceLocation;

class TextureUVCoordinateSet{
	public:
		//size:28
		char filler0[28];
	public:
		TextureUVCoordinateSet(float,float,float,float,unsigned short,unsigned short,ResourceLocation);
		TextureUVCoordinateSet(void);
		void fromOldSystem(int);
		void getFlippedVertically(void);
		void inverseOffsetHeight(float,float);
		void inverseOffsetWidth(float,float);
		void offset(float);
		void offsetHeight(float,float);
		void offsetHeightPixel(float,float);
		void offsetWidth(float,float);
		void offsetWidthPixel(float,float);
		void subTexture(float,float,int,int);
};