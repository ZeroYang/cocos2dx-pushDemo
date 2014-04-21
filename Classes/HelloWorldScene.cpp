#include "HelloWorldScene.h"
#include "push.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::onEnter()
{
    addNotificationListener();
}

void HelloWorld::onExit()
{
    removeNotificationListener();
}

void HelloWorld::addNotificationListener()
{
    notification_listener =  EventListenerCustom::create(NOTIFICATION_EVENT, [=](EventCustom* event){
        char* buf = static_cast<char*>(event->getUserData());
        CCLOG("Notification=%s",buf);
    });
    _eventDispatcher->addEventListenerWithFixedPriority(notification_listener, 1);


    register_notification_deviceToken_listener =  EventListenerCustom::create(REGISTER_NOTIFICATION_DEVICETOKEN_EVENT, [=](EventCustom* event){
        char* buf = static_cast<char*>(event->getUserData());
        CCLOG("register notification deviceToken=%s",buf);
    });
    _eventDispatcher->addEventListenerWithFixedPriority(register_notification_deviceToken_listener, 1);

    
    register_notification_error_listener =  EventListenerCustom::create(REGISTER_NOTIFICATION_ERROR_EVENT, [=](EventCustom* event){
        char* buf = static_cast<char*>(event->getUserData());
        CCLOG("register notification error=%s",buf);
    });
    _eventDispatcher->addEventListenerWithFixedPriority(register_notification_error_listener, 1);

}

void HelloWorld::removeNotificationListener()
{
    _eventDispatcher->removeEventListener(notification_listener);
    _eventDispatcher->removeEventListener(register_notification_deviceToken_listener);
    _eventDispatcher->removeEventListener(register_notification_error_listener);
}
