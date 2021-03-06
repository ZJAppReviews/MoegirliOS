//
//  moegirlWebView.h
//  moegirlwiki
//
//  Created by master on 14-10-22.
//  Copyright (c) 2014年 masterchan.me. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "mcCachedRequest.h"
#import "moegirlSaveImageAlertView.h"

@protocol moegirlWebViewDelegate <NSObject>

- (void)progressAndStatusShowUp;
- (void)progressAndStatusHide;
- (void)progressAndStatusMakeStep:(float)step info:(NSString *)info;
- (void)progressAndStatusSetToValue:(float)step info:(NSString *)info;
- (void)cancelKeyboard;
- (void)newWebViewRequestFormWebView:(NSString *)keyword;
- (void)ctrlPanelCallEditor;

@end

@interface moegirlWebView : UIWebView<UIWebViewDelegate,mcCachedRequestDelegate>
{
    @private
    NSString * templink;
}

- (void)cancelRequest;
- (NSString *)prepareContent:(NSData *)data;
- (void)loadContentWithEncodedKeyWord:(NSString *)keywordAfterEncode useCache:(BOOL)useCache;

@property (strong, nonatomic) mcCachedRequest * contentRequest;
@property (strong, nonatomic) moegirlSaveImageAlertView * saveImageAlertView;
@property (strong, nonatomic) NSString * targetURL;
@property (strong, nonatomic) NSString * keyword;

@property (assign, nonatomic) id<moegirlWebViewDelegate> hook;

@end
