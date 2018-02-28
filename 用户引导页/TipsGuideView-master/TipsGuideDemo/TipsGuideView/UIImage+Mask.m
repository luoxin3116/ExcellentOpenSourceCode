//
//  UIImage+Mask.m
//  TipsGuideDemo
//
//  Created by wangzheng on 17/6/2.
//  Copyright © 2017年 WZheng. All rights reserved.
//

#import "UIImage+Mask.h"

@implementation UIImage (Mask)

- (UIImage *)maskImage:(UIColor *)maskColor
{
    CGRect rect = CGRectMake(0, 0, self.size.width, self.size.height);
    //获取图片上下文 一个是size就是绘制的范围，还有一个是opaque,也就是这个图层是否完全透明，一般情况下最好设置为YES，这样可以让图层在渲染的时候效率更高。最关键的一个就是scale这个参数，那么这个参数的意思就是缩放比例，一般是1.0但是如果是在Retina屏幕上最好不要自己手动打个设置他的缩放比例，直接设置0，系统就会自动进行最佳的缩放
    //UIGraphicsBeginImageContext(size) = UIGraphicsBeginImageContextWithOptions(size,NO,1.0)
    UIGraphicsBeginImageContextWithOptions(rect.size, NO, 0);
    //得到当前的上下文
    CGContextRef context = UIGraphicsGetCurrentContext();
    //坐标系平移，上下文，x，y
    CGContextTranslateCTM(context, 0, rect.size.height);
    //坐标系x,y缩放
    CGContextScaleCTM(context, 1.0, -1.0);
    //使用UIImage作为mask进行裁剪，context指针，clip到context的区域，mask图片映射到context的区域   mask的图片，对于裁剪区域rect中的点是否变化取决于mask图中的alpha值，为0的话，里面的点也为透明
    CGContextClipToMask(context, rect, self.CGImage);
    //设置填充颜色
    CGContextSetFillColorWithColor(context, maskColor.CGColor);
    //填充区域
    CGContextFillRect(context, rect);
    //获取上下文生成的图片
    UIImage *smallImage = UIGraphicsGetImageFromCurrentImageContext();
    //关闭图形上下文
    UIGraphicsEndImageContext();
    
    return smallImage;
}

@end
