#ifndef LEVELEDITORSCENE_H
#define LEVELEDITORSCENE_H

#include "Scene.h"

class LevelEditorScene : public Scene
{
public:
	LevelEditorScene();
	~LevelEditorScene();

	// @Override
	void Update(float dt);


private:
	bool changingScene;
	float timeToChangeScene;
};

#endif // !LEVELEDITOR_H
