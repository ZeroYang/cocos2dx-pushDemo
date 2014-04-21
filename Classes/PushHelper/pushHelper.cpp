//
//  pushHelper.cpp
//  pushDemo
//
//  Created by YTB on 14-4-10.
//
//

#include "pushHelper.h"
#include "push.h"


// singleton stuff
static pushHelper *s_SharedPushHelper = NULL;

pushHelper* pushHelper::sharedPushHelper(void)
{
    if (!s_SharedPushHelper)
    {
        s_SharedPushHelper = new pushHelper();
    }
    
    return s_SharedPushHelper;
}

pushHelper::pushHelper()
{}

pushHelper::~pushHelper()
{}

bool pushHelper::applicationDidFinishLaunchingWithNotification(const char* notificationJson)
{
    CCLOG("applicationDidFinishLaunchingWithNotification=%s",notificationJson);

    dispatcherNotificationEvent(notificationJson, NOTIFICATION_EVENT);

    return true;
}

void pushHelper::applicationDidRegisterForRemoteNotificationsWithDeviceToken(const char *deviceToken)
{
    CCLOG("applicationDidRegisterForRemoteNotificationsWithDeviceToken=%s",deviceToken);

    dispatcherNotificationEvent(deviceToken, REGISTER_NOTIFICATION_DEVICETOKEN_EVENT);
}

void pushHelper::applicationdidFailToRegisterForRemoteNotificationsWithError(const char *error)
{
    CCLOG("FailToRegisterForRemoteNotificationsWithError=%s",error);

    dispatcherNotificationEvent(error, REGISTER_NOTIFICATION_ERROR_EVENT);
}

void pushHelper::applicationDidReceiveRemoteNotification(const char* notificationJson)
{
    CCLOG("applicationDidReceiveRemoteNotification=%s",notificationJson);

    dispatcherNotificationEvent(notificationJson, NOTIFICATION_EVENT);
}

void pushHelper::dispatcherNotificationEvent(const char* data, const char* notificationEventType)
{
    auto director = Director::getInstance();
    char* buf = new char[256];
    sprintf(buf, "%s", data);
    EventCustom event(notificationEventType);
    event.setUserData(buf);
    director->getEventDispatcher()->dispatchEvent(&event);
    CC_SAFE_DELETE_ARRAY(buf);
}