#pragma once

#include <vector>
#include "GLScene.h"
#include "Camera.h"

class GLObject3D;

class GLScene3D :
	public GLScene
{
public:
	GLScene3D();
	GLScene3D(float mx, float my, float mz);
	~GLScene3D();
	
	int AddObject(GLObject3D *obj);
	
	GLCamera *GetCamera() const;
	void SetCamera(GLCamera *camera);
	bool IsMouseVisiable() const;
	void SetMouseVisiable(bool b);
	bool IsPhysicalMouseEnable() const;
	void SetPhysicalMouseEnable(bool b);

	virtual int Render(int width, int height);
	virtual int Setup(int width, int height);
	virtual int Update(int width, int height);

	int KeyboardHandler(unsigned char key, int x, int y);
	int SpecialKeyHandler(int key, int x, int y);
	int MouseHandler(int button, int state, int x, int y);
	int MouseWheelHandler(int wheel, int direction, int x, int y);
	int MotionHandler(int x, int y);
	int PassiveMotionHandler(int x, int y);

protected:
	GLCamera *m_camera;
	std::vector<GLObject3D*> m_objects;

	bool m_physicalMouseEnable;
	bool m_mouseVisiable;
	float m_mouseRadius;
	glm::vec3 m_mouseColor;

	GLfloat *m_diffuse;
	GLfloat *m_ambient;

	void RenderMouse();
};
