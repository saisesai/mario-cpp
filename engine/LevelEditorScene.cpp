#include "LevelEditorScene.h"

#include <plog/Log.h>
#include <glm/glm.hpp>

#include "Window.h"
#include "Timer.h"
#include "ShaderManager.h"
#include "KeyboardListener.h"
#include "TextureManager.h"

LevelEditorScene::LevelEditorScene()
{
	PLOG(plog::info) << "initialize level editor scene...";

	// Create camera
	this->camera = new Camera(glm::vec2(0.0f, 0.0f));

	this->shaderPorgram = ShaderManager::MakeShaderProgram("default");
	this->texture = TextureManger::MakeTexture("Natsuki.png");

	// ===========================================
	// Generate VAO, VBO, EBO and send them to GPU
	// ===========================================
	// Create VAO
	glGenVertexArrays(1, &this->VAO);
	glBindVertexArray(this->VAO);

	// Create VBO and upload the vertex buffer
	glGenBuffers(1, &this->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertexArray), this->vertexArray, GL_STATIC_DRAW);
	
	// Create EBO and upload the indices
	glGenBuffers(1, &this->EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->elementArray), this->elementArray, GL_STATIC_DRAW);
	
	// Add the vertex attribute pointers
	int positionSize = 3;
	int colorSize = 4;
	int textureCoodsSize = 2;
	int vertexSizeBytes = (positionSize + colorSize + textureCoodsSize) * sizeof(float);
	glVertexAttribPointer(0, positionSize, GL_FLOAT, GL_FALSE, vertexSizeBytes, (void*)0);
	glVertexAttribPointer(1, colorSize, GL_FLOAT, GL_FALSE, vertexSizeBytes, (void*)(positionSize * sizeof(float)));
	glVertexAttribPointer(2, textureCoodsSize, GL_FLOAT, GL_FALSE, vertexSizeBytes,
		(void*)((positionSize + colorSize) * sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	// Unbind VAO and VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// Bind program
	glUseProgram(this->shaderPorgram);
}

LevelEditorScene::~LevelEditorScene()
{
	delete this->camera;
	glBindVertexArray(this->VAO);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);

	glDeleteBuffers(1, &this->VBO);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &this->EBO);

	glDeleteVertexArrays(1, &this->VAO);

	glBindTexture(GL_TEXTURE_2D, 0);
	glDeleteTextures(1, &this->texture);

	glUseProgram(0);
	glDeleteProgram(this->shaderPorgram);
}

void LevelEditorScene::Update(float dt)
{
	this->camera->Position.x -= dt * 50.0f;
	this->camera->Position.y -= dt * 30.0f;

	ShaderManager::UploadMatrix4f(this->shaderPorgram, "uProjection", this->camera->GetProjectionMatrix());
	ShaderManager::UploadMatrix4f(this->shaderPorgram, "uView", this->camera->GetViewMatrix());
	ShaderManager::UploadFloat(this->shaderPorgram, "uTime", Timer::GetInstance()->GetTime());

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->texture);
	ShaderManager::UploadTexture(this->shaderPorgram, "tex1", 0);

	// Bind the VAO and EBO that we are using
	// IMPORTANT bind VAO first!
	glBindVertexArray(this->VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);

	// Graw element
	glDrawElements(GL_TRIANGLES, (sizeof(this->elementArray) / sizeof(unsigned int)), GL_UNSIGNED_INT, 0);

	// Unbind the VAO and EBO
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}