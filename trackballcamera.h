#ifndef TRACKBALLCAMERA_H
#define TRACKBALLCAMERA_H

#include <iostream>


#include "irr/irrlicht.h"

#include "Constante.h"


using namespace std;
using namespace irr;
using namespace scene;     


class CSceneNodeAnimatorCameraTrackball : public ISceneNodeAnimator
{

public :


	CSceneNodeAnimatorCameraTrackball(video::IVideoDriver *driver, gui::ICursorControl *cursorControl, f32 radius, f32 moveSpeed, f32 rotateSpeed);
	
	virtual void animateNode(ISceneNode* node, u32 timeMs);
    virtual bool OnEvent(const SEvent& event);
	virtual ISceneNodeAnimator* createClone(ISceneNode* node, ISceneManager* newManager = 0);


    virtual void setMoveSpeed(f32 moveSpeed);
    virtual void setRotateSpeed(f32 rotateSpeed);

    virtual f32 getMoveSpeed() const 
	{ 
		return m_moveSpeed; 
	}
    virtual f32 getRotateSpeed() const 
	{
		return m_rotateSpeed; 
	}
    virtual bool isEventReceiverEnabled() const 
	{ 
		return true; 
	}


private :

    video::IVideoDriver *m_driver;             // pointer to video driver
    gui::ICursorControl *m_cursorControl;      // allow operations on cursor
    f32 m_radius;                              // distance from target
    f32 m_moveSpeed;                           // movements's speed to the target
    f32 m_rotateSpeed;                         // speed of fake world rotation
    bool m_isPressed;                               // is the left mouse button clicked
    bool m_wheel;                                   // did the wheel moved
    core::position2d<f32> m_cursorMove;   // contain changes on cursor position
    core::position2d<f32> m_cursorPos;    // contain the cursor position
    core::vector3df m_rotation;                // contain changes on camera position
};




#endif //TRACKBALLCAMERA_H
