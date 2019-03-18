//
//  TSYSDKManager.h
//  TSYSDK
//
//  Created by 大威 on 2016/9/28.
//  Copyright © 2016年 TSY. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TSYSDKLoginDelegate.h"
#import "TSYSDKEnterGameDelegate.h"
#import "TSYSDKPayDelegate.h"
#import "TSYSDKSwitchAccountDelegate.h"
#import "TSYSDKCashBackDelegate.h"

/** 用户中心控制器即将关闭的通知 */
extern NSString * const TSYUserCenterViewControllerWillCloseNotification;
/** 用户中心控制器已经关闭的通知 */
extern NSString * const TSYUserCenterViewControllerDidCloseNotification;

@interface TSYSDKManager : NSObject

/** 在淘手游后台注册的 appID */
@property (nonatomic, copy) NSString *appID;
/** 跳转到第其他应用后根据此参数跳转回应用 */
@property (nonatomic, copy) NSString *urlSchemes;

/** 登录相关的代理（NOTE: 一定要保证所设置的代理对象能够随时处理用户在淘手游SDK内部的登录操作） */
@property (nonatomic, weak) id<TSYSDKLoginDelegate> loginDelegate;
/** 进入游戏相关的代理 */
@property (nonatomic, weak) id<TSYSDKEnterGameDelegate> enterGameDelegate;
/** 支付相关的代理 */
@property (nonatomic, weak) id<TSYSDKPayDelegate> payDelegate;
/** 切换账号相关的代理（NOTE: 一定要保证所设置的代理对象能够随时处理用户在淘手游SDK内部的切换账号操作） */
@property (nonatomic, weak) id<TSYSDKSwitchAccountDelegate> switchAccountDelegate;
/** 退游返现相关的代理（NOTE: 一定要保证所设置的代理对象能够随时处理用户当前游戏的退游返现操作） */
@property (nonatomic, weak) id<TSYSDKCashBackDelegate> cashBackDelegate;

/**
 *  SDK 单例管理者
 *
 *  @return static instancetype
 */
+ (instancetype)sharedManager;

- (instancetype)init DEPRECATED_MSG_ATTRIBUTE("请使用 + (instancetype)sharedManager; 方法初始化");
+ (instancetype)new DEPRECATED_MSG_ATTRIBUTE("请使用 + (instancetype)sharedManager; 方法初始化");

/**
 调用此方法配置 SDK
 
 @param appID          在淘手游后台注册的 appID
 @param urlSchemes     跳转到第其他应用后根据此参数跳转回应用
 @param showMenuWindow 在这个Window类上显示控制菜单按钮(UIWindow)
 */
- (void)configWithAppID:(NSString *)appID
             urlSchemes:(NSString *)urlSchemes
         showMenuWindow:(UIView *)showMenuWindow;

/**
 处理支付结果
 
 在 UIApplicationDelegate 的代理方法中处理支付回调
 iOS 9 之前在如下代理方法中处理：
 - (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation
 iOS 9 之后使用新API处理：
 - (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString*, id> *)options
 
 @param url     URL
 @param options options
 */
- (void)handleOpenUrl:(NSURL *)url options:(NSDictionary *)options;

/**
 打开用户中心界面
 */
- (void)openUserCenterController;

/**
 打开登录控制器（成功或失败都会调用 TSYSDKLoginDelegate 中的代理方法）
 */
- (void)login;

/**
 进入游戏（成功或失败都会调用 TSYSDKEnterGameDelegate 中的代理方法）
 @param jsonInfo 包含用户和游戏角色信息的 JSON 字符串（保留参数，目前可传空字符串(@"")）
 
 **❌❌❌**常见错误: 在进入游戏时没有调用该接口，在支付时提示区服id非法。
 故需要在进入游戏时，需要调用enterGameWithJSONInfo把获取到的用户和游戏角色信息传入。
 
 */
- (void)enterGameWithJSONInfo:(NSString *)jsonInfo;

/**
 支付（成功或失败都会调用 TSYSDKPayDelegate 中的代理方法）
 
 @param servicearea_id 区服
 @param goods_price    单价
 @param goods_name     商品名称
 @param goods_count    数量
 @param goods_data     其他参数
 @param total_fee      总价
 */
- (void)payWithServiceAreaId:(NSString *)servicearea_id
                  goodsPrice:(NSString *)goods_price
                   goodsName:(NSString *)goods_name
                  goodsCount:(NSString *)goods_count
                   goodsData:(NSString *)goods_data
                    totalFee:(NSString *)total_fee;

/**
 切换账号（即用户退出账号，成功或失败都会调用 TSYSDKSwitchAccountDelegate 中的代理方法）
 */
- (void)switchAccount;

/**
 SDK版本号
 
 @return NSString
 */
- (NSString *)version;

/**
 渠道信息

 @return NSString
 */
- (NSString *)channel;

/**
 清除图片缓存
 */
- (void)removeAllImageCaches;



@end
