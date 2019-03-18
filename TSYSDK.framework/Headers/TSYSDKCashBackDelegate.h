//
//  TSYSDKCashBackDelegate.h
//  TSYSDK
//
//  Created by 大威 on 2016/11/11.
//  Copyright © 2016年 TSY. All rights reserved.
//

#ifndef TSYSDKCashBackDelegate_h
#define TSYSDKCashBackDelegate_h

/**处理用户退游返现的状态*/
typedef NS_ENUM(NSUInteger, TSYSDKCashBackHandleStatus) {
    TSYSDKCashBackHandleStatusBegin = 0,//开始处理
    TSYSDKCashBackHandleStatusEnd = 1//完成处理
};

/**用户退游返现相关的代理方法*/
@protocol TSYSDKCashBackDelegate <NSObject>

/**
 退游返现成功，会回调此代理方法

 @param manager TSYSDKManager
 */
- (void)tsySDKManager:(TSYSDKManager *)manager
      cashBackHandler:(void (^)(TSYSDKCashBackHandleStatus))handler;

@end

#endif /* TSYSDKCashBackDelegate_h */
