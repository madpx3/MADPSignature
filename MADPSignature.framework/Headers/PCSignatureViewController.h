//
//  PCSignatureViewController.h
//  CJSignatureDome
//
//  Created by BruceHu on 2019/12/3.
//
/**
 *如果使用该类进行签名，需要注意以下问题
 *1、采用presentViewController的方式，推出签名页，需要特殊设置：modalPresentationStyle 为 UIModalPresentationFullScreen，
 *因为iOS13及以上 modalPresentationStyle 默认为 UIModalPresentationAutomatic，导致签名时拖动手势与下拉关闭页面冲突。
 *为此 modalPresentationStyle 必须设置为 UIModalPresentationFullScreen，后期找到更好的方法再优化；
 *2、采用pushViewController 的方式，不需要做特殊设置，可以放心使用。
 *
 *关于结果返回：采用两种方式
 *1、代理方式返回，必须设置代理，通过代理方法返回结果
 *2、通过block方式返回，此种方法比较简单
 *
 *此两种方式根据业务需求二选一
 */

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PCSignatureViewControllerDelegate <NSObject>
// 返回签名图片
- (void)returnImage:(UIImage *)signImage;

@end

typedef void (^ConfirmSignatureBlock)(UIImage  *signImage);

@interface PCSignatureViewController : UIViewController

@property (nonatomic, assign) id<PCSignatureViewControllerDelegate> delegate;

/// 通过block方式返回签名图片
@property (nonatomic, copy) ConfirmSignatureBlock signatureCallBlock;

/// 签名线条颜色，默认是黑色
@property (nonatomic, strong) UIColor *lineColor;

/// 签名线条宽度，默认为1
@property (nonatomic, assign) CGFloat lineWidth;

@end

NS_ASSUME_NONNULL_END
