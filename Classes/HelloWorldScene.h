#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
public:
    virtual void onEnter() override;
    virtual void onExit() override;
    
private:
    void addNotificationListener();
    void removeNotificationListener();
    
private:
    cocos2d::EventListenerCustom* notification_listener;
    cocos2d::EventListenerCustom* register_notification_error_listener;
    cocos2d::EventListenerCustom* register_notification_deviceToken_listener;

};

#endif // __HELLOWORLD_SCENE_H__
