//
//  TSYSDKSwitchAccountDelegate.h
//  TSYSDK
//
//  Created by 大威 on 2016/10/11.
//  Copyright © 2016年 TSY. All rights reserved.
//

#ifndef TSYSDKSwitchAccountDelegate_h
#define TSYSDKSwitchAccountDelegate_h

/**切换账号的状态码*/
typedef NS_ENUM(NSUInteger, TSYSDKSwitchAccountStatus) {
    TSYSDKSwitchAccountStatusSuccess,//切换账号成功
    TSYSDKSwitchAccountStatusError //切换账号失败
};

/**切换账号相关的代理方法*/
@protocol TSYSDKSwitchAccountDelegate <NSObject>

/**
 切换账号（退出账号）

 @param manager TSYSDKManager
 @param status  切换账号的状态码
 @param resultDict 切换账号相关信息
 
 resultDict示例内容如下：
 {
     code = 0;
     msg = "成功";
 }
 */
- (void)  tsySDKManager:(TSYSDKManager *)manager
switchAccountWithStatus:(TSYSDKSwitchAccountStatus)status
             resultDict:(NSDictionary *)resultDict;

@end

#endif /* TSYSDKSwitchAccountDelegate_h */
