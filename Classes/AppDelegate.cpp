#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "Utility/SceneSupport/SceneCreator.h"
#include "Game/Scene/GameMain/GameMainScene.h"

using namespace cocos2d;

static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}


//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
	//set OpenGL context attributions,now can only set six attributions:
	//red,green,blue,alpha,depth,stencil
	GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };

	GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages, 
// don't modify or remove this function
static int register_all_packages()
{
	return 0; //flag for packages manager
}
bool AppDelegate::applicationDidFinishLaunching() {

    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();

	if (!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
		glview = GLViewImpl::createWithRect("GrimoArena", Rect(0, 0, mediumResolutionSize.width, mediumResolutionSize.height));
#else
		glview = GLViewImpl::create("GrimoArena");
#endif
		director->setOpenGLView(glview);
	}


    director->setDisplayStats( true );
	director->setAnimationInterval( 1.f / 60.f );

	glview->setDesignResolutionSize(mediumResolutionSize.width, mediumResolutionSize.height, ResolutionPolicy::NO_BORDER);
	Size frameSize = glview->getFrameSize();

	if (frameSize.height > mediumResolutionSize.height) {
		director->setContentScaleFactor(MIN(largeResolutionSize.height / designResolutionSize.height, largeResolutionSize.width / designResolutionSize.width));
	}

	else if (frameSize.height > smallResolutionSize.height) {
		director->setContentScaleFactor(MIN(smallResolutionSize.height / designResolutionSize.height, smallResolutionSize.width / designResolutionSize.width));
	}

	register_all_packages;

	auto firstScene = SceneCreator::createPhysicsScene(GameMainScene::create(), Vect(0, -9.8f), 1.0f, true);
	auto scene = TransitionFade::create(1.5f, firstScene, Color3B::BLACK);
	director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
