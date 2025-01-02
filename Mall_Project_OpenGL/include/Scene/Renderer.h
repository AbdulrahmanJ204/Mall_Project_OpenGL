#pragma once
#include "core.h"

#include "VAO.h"
#include "EBO.h"
#include "Shader.h"
class Renderer {
public:
	Renderer();
	~Renderer();
	void Clear();
	void Draw(VAO& va, EBO& ib, Shader& shader);
};

