#ifndef LEVELEDITORSCENE_H
#define LEVELEDITORSCENE_H

#include "Scene.h"

#include <gl/glew.h>

class LevelEditorScene : public Scene
{
public:
	LevelEditorScene();
	~LevelEditorScene();

	// @Override
	void Update(float dt);


private:

	const char* vertexShaderSource = "#version 330 core\n \
        \n \
        layout (location=0) in vec3 aPos;\n \
        layout (location=1) in vec4 aColor;\n \
        \n \
        out vec4 fColor;\n \
        \n \
        void main()\n \
        {\n \
            fColor = aColor;\n \
            gl_Position = vec4(aPos, 1.0);\n \
        }\n";

    const char* fragmentShaderSource = "#version 330 core\n \
        \n \
        in vec4 fColor;\n \
        \n \
        out vec4 color;\n \
        \n \
        void main()\n \
        {\n \
            color = fColor;\n \
        }\n";

    float vertexArray[28] = {
        // position         // color
        -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, // Top left
        0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, // Top right
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f // Bottom left
    };

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
	GLuint VAO, VBO, EBO;
};

#endif // !LEVELEDITOR_H
