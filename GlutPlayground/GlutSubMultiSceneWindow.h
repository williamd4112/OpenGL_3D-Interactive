#pragma once

#include <vector>

#include "GLScene3D.h"
#include "GlutSubWindow.h"

class GlutSubMultiSceneWindow
	: public GlutSubWindow
{
public:
	GlutSubMultiSceneWindow(GlutWindowDescriptor parentGd, int nRows, int nCols);
	~GlutSubMultiSceneWindow();

	void AddScene(GLScene *scene);
	GLScene *GetScene(int index) const;

	int Display();
	int KeyboardHandler(unsigned char key, int x, int y);
	int SpecialKeyHandler(int key, int x, int y);
	int MouseHandler(int button, int state, int x, int y);
	int MouseWheelHandler(int wheel, int direction, int x, int y);
	int MotionHandler(int x, int y);
	int PassiveMotionHandler(int x, int y);

private:
	int m_nRows;
	int m_nCols;

	std::vector<GLScene*> m_scenes;
};
