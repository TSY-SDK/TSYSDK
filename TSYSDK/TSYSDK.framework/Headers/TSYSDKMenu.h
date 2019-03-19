//
//  TSYSDKMenu.h
//  TSYSDK
//
//  Created by 大威 on 2016/9/29.
//  Copyright © 2016年 TSY. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TSYSDKMenu : UIView

/**
 控制菜单收缩状态
 */
@property (nonatomic, assign) BOOL isShrink;

/**
 是否正在拖动
 */
@property (nonatomic, assign) BOOL isDragging;

/**
 设置此 window 用于显示控制菜单
 */
@property (nonatomic, weak) UIView *window;

/**
 *  SDK 控制菜单单例管理者
 *
 *  @return static instancetype
 */
+ (instancetype)sharedMenu;

- (instancetype)init DEPRECATED_MSG_ATTRIBUTE("请使用 + (instancetype)sharedMenu; 方法初始化");
+ (instancetype)new DEPRECATED_MSG_ATTRIBUTE("请使用 + (instancetype)sharedMenu; 方法初始化");

/**
 将此控制菜单显示到最前面
 */
- (void)showToFront;

@end
