#pragma once

#include <unordered_map>

#include <vector>

#include <string>

#include "Transform.h"

#include "Renderer.h"

#include "Material.h"

#include "Texture.h"

#include "Bone.h"

struct MeshRendererInfo;

class MeshRenderer :public Renderer
{
public:
	MeshRenderer();

	~MeshRenderer();

	void Draw()override;

public:
	bool Load(const std::string& _path);

	void Release();

	std::string GetPath()const { return path; }

	Material* GetMaterial(unsigned _count);
	Texture* GetTexture(unsigned _count);
	Bone* GetBone(unsigned _count);

	Material* GetMaterial(const std::string& _name);
	Texture* GetTexture(const std::string& _name);
	Bone* GetBone(const std::string& _name);

public:
	Transform renderTransform;

	float alpha;//透明度（0～1・0で透明、1で不透明）

	COLOR_F
		diffuse, //拡散スケール（0～1）
		specular, //鏡面スケール（0～1）
		ambient, //環境スケール（0～1）
		emissive;//自己発光色スケール（0～1）

private:
	MeshRendererInfo* info;

	std::string path;

	std::vector<Material> materials;

	std::vector<Texture> textures;

	std::vector<Bone> bones;

	static std::unordered_map<std::string, MeshRendererInfo> meshInfo;

};
