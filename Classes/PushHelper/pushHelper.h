//
//  pushHelper.h
//  pushDemo
//
//  Created by YTB on 14-4-10.
//
//

#ifndef __pushDemo__pushHelper__
#define __pushDemo__pushHelper__

#include "cocos2d.h"

USING_NS_CC;

class  pushHelper
{
public:
    pushHelper();
    ~pushHelper();
    
public:
    /** returns a shared instance of the pushHelper
     *  @js getInstance
     */
    static pushHelper* sharedPushHelper(void);

    /**
     @brief  The function be called when the application launching receive remote notification
     @param  notificationJson the pointer of the notification json string
     */
    bool applicationDidFinishLaunchingWithNotification(const char* notificationJson);
    
    /**
     @brief  The function be called when the application register remote notification success
     @param  deviceToken the pointer of the notification token string
     */
    void applicationDidRegisterForRemoteNotificationsWithDeviceToken(const char *deviceToken);

    /**
     @brief  The function be called when the application register remote notification failed
     @param  error the pointer of the register remote notification failed string
     */
    void applicationdidFailToRegisterForRemoteNotificationsWithError(const char *error);
    
    /**
     @brief  The function be called when the application running receive remote notification
     @param  notificationJson the pointer of the notification json string
     */
    void applicationDidReceiveRemoteNotification(const char* notificationJson);
    
private:
    void dispatcherNotificationEvent(const char* data, const char* notificationEventType);
    
};

#endif /* defined(__pushDemo__pushHelper__) */
