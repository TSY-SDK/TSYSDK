//
//  TSYSDKLoginDelegate.h
//  TSYSDK
//
//  Created by 大威 on 2016/10/11.
//  Copyright © 2016年 TSY. All rights reserved.
//

#ifndef TSYSDKLoginDelegate_h
#define TSYSDKLoginDelegate_h

@class TSYSDKManager;
/**登录状态*/
typedef NS_ENUM(NSUInteger, TSYSDKLoginStatus) {
    TSYSDKLoginStatusSuccess,    //登录成功
    TSYSDKLoginStatusError,      //登录出错
    TSYSDKLoginStatusUserCancel  //用户取消登录
};

/**
 登录相关的代理方法
 */
@protocol TSYSDKLoginDelegate <NSObject>

/**
 登录的回调方法
 登录控制器只有在用户登录成功和用户取消登录的情况下才会关闭，用户登录出错并不会关闭登录控制器
 
 @param manager    TSYSDKManager
 @param status     登录状态码
 @param resultDict 登录相关信息
 
 resultDict示例内容如下：
 {
     code = 0;
     msg = "成功";
     token = 22219733425f3298bcf5b8423af32cfec308c56bb914981e19f9f3fac3e324aa;
     userId = 5ec325d17e7f2ad56a060c36;
 }
 */
- (void)tsySDKManager:(TSYSDKManager *)manager
      loginWithStatus:(TSYSDKLoginStatus)status
           resultDict:(NSDictionary *)resultDict;

@end

#endif /* TSYSDKLoginDelegate_h */
