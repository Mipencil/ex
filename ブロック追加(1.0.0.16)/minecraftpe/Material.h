#pragma once

#include <vector>
#include <memory>

#include "MaterialType.h"

class Material{
	public:
		static std::vector<std::unique_ptr<Material, std::default_delete<Material>>> mMaterials;
	public:
		//size:22
		char filler0[22];
	public:
		static Material& getMaterial(MaterialType);
};