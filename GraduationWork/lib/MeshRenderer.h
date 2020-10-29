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

	float alpha;//�����x�i0�`1�E0�œ����A1�ŕs�����j

	COLOR_F
		diffuse, //�g�U�X�P�[���i0�`1�j
		specular, //���ʃX�P�[���i0�`1�j
		ambient, //���X�P�[���i0�`1�j
		emissive;//���Ȕ����F�X�P�[���i0�`1�j

private:
	MeshRendererInfo* info;

	std::string path;

	std::vector<Material> materials;

	std::vector<Texture> textures;

	std::vector<Bone> bones;

	static std::unordered_map<std::string, MeshRendererInfo> meshInfo;

};
