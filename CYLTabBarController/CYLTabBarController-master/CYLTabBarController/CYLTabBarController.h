//
//  CYLTabBarController.h
//  CYLTabBarController
//
//  v1.16.0 Created by 微博@iOS程序犭袁 ( http://weibo.com/luohanchenyilong/ ) on 10/20/15.
//  Copyright © 2015 https://github.com/ChenYilong . All rights reserved.
//

#import "CYLPlusButton.h"
#import "UIViewController+CYLTabBarControllerExtention.h"
#import "UIView+CYLTabBarControllerExtention.h"
#import "UITabBarItem+CYLTabBarControllerExtention.h"
#import "UIControl+CYLTabBarControllerExtention.h"

@class CYLTabBarController;
//加载完成后回调
typedef void(^CYLViewDidLayoutSubViewsBlock)(CYLTabBarController *tabBarController);
//使用这种外部方法在检测字符串的值是否相等的时候更快.直接使用指针
//可以直接使用(stringInstance == MyFirstConstant)来比较,
//而define则使用的是这种.([stringInstance isEqualToString:MyFirstConstant])
FOUNDATION_EXTERN NSString *const CYLTabBarItemTitle;
FOUNDATION_EXTERN NSString *const CYLTabBarItemImage;
FOUNDATION_EXTERN NSString *const CYLTabBarItemSelectedImage;
FOUNDATION_EXTERN NSUInteger CYLTabbarItemsCount;
FOUNDATION_EXTERN NSUInteger CYLPlusButtonIndex;
FOUNDATION_EXTERN CGFloat CYLPlusButtonWidth;
FOUNDATION_EXTERN CGFloat CYLTabBarItemWidth;

@protocol CYLTabBarControllerDelegate <NSObject>

/*!
 * @param tabBarController The tab bar controller containing viewController.
 * @param control Selected UIControl in TabBar.
 */
- (void)tabBarController:(UITabBarController *)tabBarController didSelectControl:(UIControl *)control;

@end

@interface CYLTabBarController : UITabBarController <CYLTabBarControllerDelegate>

@property (nonatomic, copy) CYLViewDidLayoutSubViewsBlock viewDidLayoutSubviewsBlock;

/**
 这里为何需要声明？
 */
- (void)setViewDidLayoutSubViewsBlock:(CYLViewDidLayoutSubViewsBlock)viewDidLayoutSubviewsBlock;

/*!
 * An array of the root view controllers displayed by the tab bar interface.
 */
@property (nonatomic, readwrite, copy) NSArray<UIViewController *> *viewControllers;

/*!
 * The Attributes of items which is displayed on the tab bar.
 */
@property (nonatomic, readwrite, copy) NSArray<NSDictionary *> *tabBarItemsAttributes;

/*!
 * Customize UITabBar height
 */
@property (nonatomic, assign) CGFloat tabBarHeight;

/*!
 * To set both UIBarItem image view attributes in the tabBar,
 * default is UIEdgeInsetsZero.
 */
//设置图片的内边距
@property (nonatomic, readonly, assign) UIEdgeInsets imageInsets;

/*! 
 * To set both UIBarItem label text attributes in the tabBar,
 * use the following to tweak the relative position of the label within the tab button (for handling visual centering corrections if needed because of custom text attributes)
 */
//设置文字的内边距
@property (nonatomic, readonly, assign) UIOffset titlePositionAdjustment;
//设置内容
@property (nonatomic, readonly, copy) NSString *context;
//设置控制器和上面的相关属性
- (instancetype)initWithViewControllers:(NSArray<UIViewController *> *)viewControllers
                  tabBarItemsAttributes:(NSArray<NSDictionary *> *)tabBarItemsAttributes;
//提供的类方法
+ (instancetype)tabBarControllerWithViewControllers:(NSArray<UIViewController *> *)viewControllers
                              tabBarItemsAttributes:(NSArray<NSDictionary *> *)tabBarItemsAttributes;
//增加了图片的内边距和文字的位置偏西属性
- (instancetype)initWithViewControllers:(NSArray<UIViewController *> *)viewControllers
                  tabBarItemsAttributes:(NSArray<NSDictionary *> *)tabBarItemsAttributes
                            imageInsets:(UIEdgeInsets)imageInsets
                titlePositionAdjustment:(UIOffset)titlePositionAdjustment;
//同样的类方法
+ (instancetype)tabBarControllerWithViewControllers:(NSArray<UIViewController *> *)viewControllers
                              tabBarItemsAttributes:(NSArray<NSDictionary *> *)tabBarItemsAttributes
                                        imageInsets:(UIEdgeInsets)imageInsets
                            titlePositionAdjustment:(UIOffset)titlePositionAdjustment;
//增加环境,上下文? 不知道干嘛的
- (instancetype)initWithViewControllers:(NSArray<UIViewController *> *)viewControllers
                  tabBarItemsAttributes:(NSArray<NSDictionary *> *)tabBarItemsAttributes
                            imageInsets:(UIEdgeInsets)imageInsets
                titlePositionAdjustment:(UIOffset)titlePositionAdjustment
                                context:(NSString *)context;
//同样的类方法
+ (instancetype)tabBarControllerWithViewControllers:(NSArray<UIViewController *> *)viewControllers
                              tabBarItemsAttributes:(NSArray<NSDictionary *> *)tabBarItemsAttributes
                                        imageInsets:(UIEdgeInsets)imageInsets
                            titlePositionAdjustment:(UIOffset)titlePositionAdjustment
                                            context:(NSString *)context;

//是否可以选中当前的控制器模块
- (void)updateSelectionStatusIfNeededForTabBarController:(UITabBarController *)tabBarController shouldSelectViewController:(UIViewController *)viewController;
//是否隐藏提示数字的背后的分割线
- (void)hideTabBadgeBackgroundSeparator;

/*!
 * Judge if there is plus button.
 */
//是否有中间添加按钮
+ (BOOL)havePlusButton;

/*!
 * @attention Include plusButton if exists.
 */
//所有tabbar的个数
+ (NSUInteger)allItemsInTabBarCount;
//获取总代理
- (id<UIApplicationDelegate>)appDelegate;
//获取keywindow
- (UIWindow *)rootWindow;

@end
//添加的分类
@interface NSObject (CYLTabBarControllerReferenceExtension)

/*!
 * If `self` is kind of `UIViewController`, this method will return the nearest ancestor in the view controller hierarchy that is a tab bar controller. If `self` is not kind of `UIViewController`, it will return the `rootViewController` of the `rootWindow` as long as you have set the `CYLTabBarController` as the  `rootViewController`. Otherwise return nil. (read-only)
 */
@property (nonatomic, setter=cyl_setTabBarController:) CYLTabBarController *cyl_tabBarController;

@end

FOUNDATION_EXTERN NSString *const CYLTabBarItemWidthDidChangeNotification;
