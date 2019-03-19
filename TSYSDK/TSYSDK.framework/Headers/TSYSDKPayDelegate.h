//
//  TSYSDKPayDelegate.h
//  TSYSDK
//
//  Created by 大威 on 2016/10/11.
//  Copyright © 2016年 TSY. All rights reserved.
//

#ifndef TSYSDKPayDelegate_h
#define TSYSDKPayDelegate_h

/**
 支付方式
 */
typedef NS_ENUM(NSUInteger, TSYPayType) {
    TSYPayTypeUnSelected = 10000,//还未选择支付方式
    TSYPayTypeCoin = 99,         //淘手游余额支付
    TSYPayTypeTSYBalance = 0,    //便宜玩平台币支付
    TSYPayTypeAli = 16,          //支付宝 支付
    TSYPayTypeWeChat = 13,       //微信支付
    TSYPayTypeUnion = 18         //银联支付
};

/**
 支付的状态码
 */
typedef NS_ENUM(NSUInteger, TSYPayStatus) {
    TSYPayStatusSuccess = 0,      //订单支付成功
    TSYPayStatusError = 1,        //订单支付失败
    TSYPayStatusProcessing = 2,   //订单正在处理中
    TSYPayStatusUserCancel = 3,   //用户中途取消支付
    TSYPayStatusNetworkError = 4, //网络错误
    TSYPayStatusUserNeedLogin = 5 //用户需要重新登录
};

@class TSYSDKManager;

/**
 支付相关的代理方法
 */
@protocol TSYSDKPayDelegate <NSObject>

@optional

/**
 支付成功的回调方法
 
 @param manager TSYSDKManager
 @param type    支付方式
 */
- (void)tsySDKManager:(TSYSDKManager *)manager
   paySuccessWithType:(TSYPayType)type
               status:(TSYPayStatus)status;

/*
 支付失败的回调方法
 
 @param manager TSYSDKManager
 @param type    支付方式
 @param status  支付失败类型
 */
- (void)tsySDKManager:(TSYSDKManager *)manager
   payFailureWithType:(TSYPayType)type
               status:(TSYPayStatus)status;

@end

#endif /* TSYSDKPayDelegate_h */
