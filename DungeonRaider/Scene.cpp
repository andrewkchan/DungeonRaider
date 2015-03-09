#include "Scene.h"
#include "StaticSpriteComponent.h"
#include "ZWorld.h"

Scene::Scene()
{
	world = new ZWorld();
	levelTextures.loadTexture("skeleton_idle", "Textures/skeleton_idle.png");
	sf::Sprite skeletonSprite;
	skeletonSprite.setTexture(levelTextures.getTexture("skeleton_idle"));
	skeletonSprite.setScale(0.1f, 0.1f);

	skelly.addDrawableComponent(new StaticSpriteComponent(skeletonSprite));
	pc.linkCharacter(&skelly);

}
Scene::Scene(sf::Texture& backgroundTex)
{
	world = new ZWorld();

	levelTextures.loadTexture("skeleton", "Textures/skeleton_idle.png");
	sf::Sprite skeletonSprite;
	skeletonSprite.setTexture(levelTextures.getTexture("skeleton_idle"));
	skeletonSprite.setScale(0.1f, 0.1f);

	skelly.addDrawableComponent(new StaticSpriteComponent(skeletonSprite));
	pc.linkCharacter(&skelly);
	skelly.getPhysicsComponent().setAbsMaxSpeed(10.0f);
}
void Scene::drawToWindow(sf::RenderWindow& window)
{
	//world.drawToWindow(window);
	skelly.drawToWindow(window);
	pc.drawGUIToWindow(window);
}
void Scene::update(float frameTime)
{
	skelly.update(frameTime);
	pc.update(frameTime);
	//std::cout << "exec x:" << test.x << "exec y:" << test.y << "exec z:" << test.z << "exec w:" << test.w << std::endl;
}
void Scene::getInput()
{
	pc.handleInput();
}
Scene::~Scene()
{

}