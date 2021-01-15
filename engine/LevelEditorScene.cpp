#include "LevelEditorScene.h"
#include <plog/Log.h>

#include "Window.h"
#include "ShaderManager.h"
#include "KeyboardListener.h"

LevelEditorScene::LevelEditorScene()
{
	PLOG(plog::info) << "initialize level editor scene...";
	this->shaderPorgram = ShaderManager::MakeShaderProgram(this->vertexShaderSource, this->fragmentShaderSource);

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
	int vertexSizeBytes = (positionSize + colorSize) * sizeof(float);
	glVertexAttribPointer(0, positionSize, GL_FLOAT, GL_FALSE, vertexSizeBytes, (void*)0);
	glVertexAttribPointer(1, colorSize, GL_FLOAT, GL_FALSE, vertexSizeBytes, (void*)(positionSize * sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	

	// Unbind VAO and VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	

	// Bind program
	glUseProgram(this->shaderPorgram);
}

LevelEditorScene::~LevelEditorScene()
{
	glBindVertexArray(this->VAO);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);

	glDeleteBuffers(1, &this->VBO);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &this->EBO);

	glDeleteVertexArrays(1, &this->VAO);

	glUseProgram(0);
	glDeleteProgram(this->shaderPorgram);
}

void LevelEditorScene::Update(float dt)
{
	// Bind the VAO and EBO that we are using
	// IMPORTANT bind VAO first!
	glBindVertexArray(this->VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	

	// Graw element
	glDrawElements(GL_TRIANGLES, (sizeof(this->elementArray) / sizeof(unsigned int)), GL_UNSIGNED_INT, 0);

	// Unbind the VAO and EBO
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}