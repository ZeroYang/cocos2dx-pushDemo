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
    CCNotificationCenter::sharedNotificationCenter()->postNotification(REMOTE_NOTIFICATION, new CCString(notificationJson));
    return true;
}

void pushHelper::applicationDidRegisterForRemoteNotificationsWithDeviceToken(const char *deviceToken)
{
    CCLOG("applicationDidRegisterForRemoteNotificationsWithDeviceToken=%s",deviceToken);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(REGISTER_REMOTE_NOTIFICATION_DEVICE_TOKEN, new CCString(deviceToken));
}

void pushHelper::applicationdidFailToRegisterForRemoteNotificationsWithError(const char *error)
{
    CCLOG("FailToRegisterForRemoteNotificationsWithError=%s",error);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(REGISTER_REMOTE_NOTIFICATION_ERROR, new CCString(error));
}

void pushHelper::applicationDidReceiveRemoteNotification(const char* notificationJson)
{
    CCLOG("applicationDidReceiveRemoteNotification=%s",notificationJson);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(REMOTE_NOTIFICATION, new CCString(notificationJson));
}