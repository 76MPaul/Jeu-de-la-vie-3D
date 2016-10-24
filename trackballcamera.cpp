#include <iostream>

#include "irr/irrlicht.h"
#include "Constante.h"
#include "trackballcamera.h"
 
using namespace std;	
using namespace irr;
using namespace scene;    

#define MAXANGLE 1.5


CSceneNodeAnimatorCameraTrackball::CSceneNodeAnimatorCameraTrackball(
    video::IVideoDriver *driver,
    gui::ICursorControl *cursorControl,
    f32 radius,
    f32 moveSpeed,
    f32 rotateSpeed)
    : m_driver(driver),
    m_cursorControl(cursorControl),
    m_radius(radius),
    m_moveSpeed(moveSpeed),
    m_rotateSpeed(rotateSpeed),
    m_isPressed(false),
    m_wheel(false)
{
    m_rotation = core::vector3df(1.0f,1.0f,0.0f);
    m_cursorPos = m_cursorControl->getRelativePosition();
    m_cursorMove = core::position2d<irr::f32>(0,0);
} 


void CSceneNodeAnimatorCameraTrackball::animateNode(ISceneNode* node, u32 timeMs)
{
    // check the node is a camera
    if (!node || node->getType() != ESNT_CAMERA) 
	{ 
		return; 
	}
    ICameraSceneNode* camera = static_cast<ICameraSceneNode*>(node);
    ISceneManager * sceneManager = camera->getSceneManager();
    // check the camera is operational
    if(!camera->isInputReceiverEnabled()) 
	{ 
		return; 
	}
    if(sceneManager && sceneManager->getActiveCamera() != camera) 
	{ 
		return; 
}

    // if there is change to apply
    if (m_isPressed || m_wheel)
    {
        f32 posZ = m_radius * cos(m_rotation.Y);
        f32 posY = m_radius * sin(m_rotation.Y);

        core::vector3df camPos(core::vector3df(0.0f, posY, posZ));
        camPos.rotateXZBy(-m_rotation.X*40, core::vector3df(0.0f, 0.0f, 0.0f));

        camera->setPosition(camPos);
        m_wheel = false;
    }
}

bool CSceneNodeAnimatorCameraTrackball::OnEvent(const SEvent& event)
{
    if(event.EventType == EET_MOUSE_INPUT_EVENT) 
	{
        if (event.MouseInput.Event == EMIE_LMOUSE_PRESSED_DOWN)
		{
            m_isPressed = true;
			return true;
		}
		else if (event.MouseInput.Event == EMIE_LMOUSE_LEFT_UP) 
		{
				m_isPressed = false;
				return true;
		}
		// change the radius/distance according to wheel moves
		else if (event.MouseInput.Event == EMIE_MOUSE_WHEEL)
		{
				if ( event.MouseInput.Wheel > 0 ) 
				{ 
					m_radius -= 1.0f * m_moveSpeed; 
				}
				else 
				{ 
					m_radius += 1.0f * m_moveSpeed; 
				}
				m_wheel = true;
				return true;
		}
		else if (event.MouseInput.Event == EMIE_MOUSE_MOVED) 
		{
				// if the mouse moves without the left button is pressed,
				// we just update the position. Camera doesn't move
				if (m_isPressed == false) 
				{
					m_cursorPos = m_cursorControl->getRelativePosition();
					return true;
				}
				// if the left button is pressed, then we get the change and
				// set the rotation vector. And update the position
				else if (m_isPressed == true) 
				{
					m_cursorMove = m_cursorControl->getRelativePosition() - m_cursorPos;
					m_rotation.X += m_cursorMove.X * m_rotateSpeed;
					m_rotation.Y += m_cursorMove.Y * m_rotateSpeed;
					// check the Y change to prevent vertical looping
					if (m_rotation.Y >= MAXANGLE) 
					{ 
						m_rotation.Y = MAXANGLE; 
					}
					else if (m_rotation.Y <= -MAXANGLE) 
					{ 
						m_rotation.Y = -MAXANGLE;
					}
					m_cursorPos = m_cursorControl->getRelativePosition();
					return true;
				}
		}
    }
    return false;   // event not proceeded
}

void CSceneNodeAnimatorCameraTrackball::setMoveSpeed(f32 moveSpeed)
{
	m_moveSpeed = moveSpeed;
}
void CSceneNodeAnimatorCameraTrackball::setRotateSpeed(f32 rotateSpeed)
{
	m_rotateSpeed = rotateSpeed;
}

ISceneNodeAnimator* CSceneNodeAnimatorCameraTrackball::createClone(ISceneNode* node,ISceneManager* newManager)
{
	return 0;
}
