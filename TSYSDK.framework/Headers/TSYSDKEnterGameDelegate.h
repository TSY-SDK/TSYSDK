//
//  TSYSDKEnterGameDelegate.h
//  TSYSDK
//
//  Created by 大威 on 2016/10/11.
//  Copyright © 2016年 TSY. All rights reserved.
//

#ifndef TSYSDKEnterGameDelegate_h
#define TSYSDKEnterGameDelegate_h

@class TSYSDKManager;

typedef NS_ENUM(NSUInteger, TSYSDKEnterGameStatus) {
    TSYSDKEnterGameStatusSuccess,      //进入游戏成功
    TSYSDKEnterGameStatusError,        //进入游戏失败
    TSYSDKEnterGameStatusUserNeedLogin //用户需要重新登录
};

/**
 进入游戏相关的代理方法
 */
@protocol TSYSDKEnterGameDelegate <NSObject>

@optional

/**
 进入游戏的回调方法
 
 @param manager    TSYSDKManager
 @param status     进入游戏状态码
 @param resultDict 进入游戏相关信息
 
 resultDict示例内容如下：
 {
     code = 0;
     msg = "成功";
 }
 */
- (void)tsySDKManager:(TSYSDKManager *)manager
  enterGameWithStatus:(TSYSDKEnterGameStatus)status
           resultDict:(NSDictionary *)resultDict;

@end

#endif /* TSYSDKEnterGameDelegate_h */
