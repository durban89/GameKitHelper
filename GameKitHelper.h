//
//  GameKitHelper.h
//  Simple GameKit
//
//  Created by david on 13-8-22.
//  Copyright (c) 2013年 WalkerFree. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <GameKit/GameKit.h>

#define DO_DATA_CALLBACK(X, Y) if (self.dataDelegate && [self.dataDelegate respondsToSelector:@selector(X)]) [self.dataDelegate performSelector:@selector(X) withObject:Y];
#define showAlert(format, ...) myShowAlert(__LINE__, (char *)__FUNCTION__, format, ##__VA_ARGS__)
#define BARBUTTON(TITLE, SELECTOR) [[UIBarButtonItem alloc] initWithTitle:TITLE style:UIBarButtonItemStylePlain target:self action:SELECTOR]



@protocol GameKitHelperDataDelegate <NSObject>
@optional
-(void) connectionEstablished;
-(void) connectionLost;
-(void) sentData: (NSString *) errorMessage;
-(void) receivedData: (NSData *)data;
@end


@interface GameKitHelper : NSObject<GKPeerPickerControllerDelegate, GKSessionDelegate>
{
    NSString *sessionID;
    id<GameKitHelperDataDelegate> dataDelegate;
    UIViewController *viewController;
    
    GKSession *session;
    BOOL isConnected;
}

@property (retain) id dataDelegate;
@property (retain) UIViewController *viewController;
@property (retain) NSString *sessionID;
@property (retain) GKSession *session;
@property (assign) BOOL isConnected;

+(void) connect;
+(void) disconnect;
+(void) sendData: (NSData *)data;
+(void) assignViewController: (UIViewController *) aViewController;
+(GameKitHelper *) sharedInstance;
@end
