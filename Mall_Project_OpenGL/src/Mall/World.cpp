#include "World.h"
#include <Scene.h>

World::World() :
	skybox(
		{
			"assets/textures/skybox1/right.jpg",
			"assets/textures/skybox1/left.jpg",
			"assets/textures/skybox1/top.jpg",
			"assets/textures/skybox1/bottom.jpg",
			"assets/textures/skybox1/front.jpg",
			"assets/textures/skybox1/back.jpg"
		}),
	wheel()
{
	//wheel.setTargetRotation(0.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	setTex();
}


void World::onImguiRender() {
	//ImGui::SliderFloat("World Rotation ", &m_RotationAngle, 0.0f, 360.0f);
	ImGui::SliderFloat3(" Position wheel", &m_Position.x, -200.0f, 200.0f);
	//electronicRoom.onImguiRender();
}
void World::drawOpaque()
{
	wheel.setParentModel(getModel());
	drawSkyBox();
	wheel.setPosition(m_Position);
	wheel.update();

	// 3. ÷»ÿ «·„Êﬁ⁄ «·√”«”Ì ( √ﬂœ √‰ «· œÊÌ— «·«› —«÷Ì ··⁄Ã·… ’ÕÌÕ)
	//wheel.setPosition(glm::vec3(0, 0, 0));
	//static float rollingAngle = 0.0f;
	//rollingAngle += 1.0f; 
	//if (rollingAngle > 360.0f) rollingAngle -= 360.0f;
	//wheel.setPosition(glm::vec3(0, 0, 0));
	//wheel.setRotation(rollingAngle, glm::vec3(1.0f, 0.0f, 0.0f)); // «·œÊ—«‰ ÕÊ· „ÕÊ—Â«
	//wheel.updateModelMatrix(); //  ÕœÌÀ «·„’›Ê›… · ÿ»Ìﬁ «·“«ÊÌ… «·ÃœÌœ…
	wheel.drawOpaque();
}
void World::drawSkyBox()
{
	glm::mat4 p = Scene::getProjection(), v = Scene::getView();
	skybox.draw(v, p);
}

void World::getTransparent()
{

}


void World::setTex()
{

}
// ? NOTES :
// ! 1- Dont forget to use public when inheriting from Object class" class Class : public Object".
// ! 2- Dont forget to setParentModel(getModel()) for all of the class children
// ! 3- if the object have a transparent Texture , call obj.getTransparent in getTransparent Method
// ! 4- dont forget to updateModelMatrix inside each draw call to see the result 
// !	    when dealing with Imgui  (not Necessary if not using it i guess).
// ! 5- Cylinder Class does not work with transparent texture for now ,maybe in the future.
// 
// ? How to draw:
// ! declare the object in header file 
// ! ModelObject model , Box box , Cylinder cylinder
// ? For transparent objects :
// ! there is an issue when drawing the same object in multiple places , like in chair class we created
// 	 ! for now just do objects as the number of the positions  "Like in Chair class , check rjls vector".
//  ? JUST FOR TRANSPARENT , Opaque work fine with it.
// 
// 
// 
// ? For Models : " The class could have some errors , it is not final"
// !	in the constructor pass the model path , default vertex and fragment shader 
// ! ModelObject inherits Object class , you can deal with all its methods (setPosition , rotation...)
// ! To Draw the model , call drawOpaque , no Transparent for now ( maybe in the future)
// ! NOTE : if the texture is not right , go to the texture and flip it vertically.
// ? For Box :
// 	   ! pass the width , height , depth , vertex and fragment shader
// 	   ! dont forget to call getTrasnparent if it does have transparent faces.
// ? For Cylinder :
// 	   ! pass the upper and lower radius  , segmentCounts , vertex and fragment shaders
// 	   ! the Segment count is the resolution of the circle , higher is smoother
// 	   ! when using a small number like 4 or 5 , you got a regular shape with the segments you passed
// 	   TODO Just try it yourself
// ?Model Example:
	///className (parameters) :
	/// model("assets/objects/w_knife.mdl", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
	// !In Consturctor :
	///  "optoinal translations"
	// !in drawOpaque:
	/// model.setParentModel(getModel());
	/// model.setPoistion(...);
	/// .
	/// .
	/// model.drawOpaque();

// ?NOTE : 
// !you can see box and cylinder examples in ResturantRoom class.	


// ?ImGui : 
// ! soon...

