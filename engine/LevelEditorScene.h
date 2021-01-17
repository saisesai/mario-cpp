#ifndef LEVELEDITORSCENE_H
#define LEVELEDITORSCENE_H

#include "Scene.h"
#include "Camera.h"

#include <gl/glew.h>

class LevelEditorScene : public Scene
{
public:
	LevelEditorScene();
	~LevelEditorScene();

	// @Override
	void Update(float dt);


private:
   Camera* camera;
    ///*
    float vertexArray[36] = {
        // position x3        // color x4             // texure x2
        0.0f, 100.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, // Top left
        100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, // Top right
        100.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, // Bottom right
        0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f // Bottom left
    };
    //*/

   /*
    float vertexArray[28] = {
        // position         // color
        -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, // Top left
        0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, // Top right
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f // Bottom left
    };
   */

    // IMPORTANT: Must be in counter-clockwise order.
    /*
     * 0(1.3)(2.1)        1(1.2))
     *
     *
     * 3(2.2)             2(1.1)(2.3)
     * */
    unsigned int elementArray[6] = {
            2, 1, 0,
            2, 0, 3
    };

	GLuint shaderPorgram;
    GLuint texture;
	GLuint VAO, VBO, EBO;
};

#endif // !LEVELEDITOR_H
