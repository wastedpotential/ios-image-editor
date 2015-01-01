//
//  ImageEditorView.h
//  ImageEditor
//
//  Created by Andy Watt on 12/24/14.
//  Copyright (c) 2014 Heitor Ferreira. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface WPImageEditorView : UIView

@property (strong, nonatomic) UIImage *sourceImage;
@property (strong, nonatomic) UIImage *previewImage;
@property (strong, nonatomic, readonly) UIImage *croppedImage;

@property(nonatomic,assign) BOOL panEnabled;
@property(nonatomic,assign) BOOL rotateEnabled;
@property(nonatomic,assign) BOOL scaleEnabled;
@property(nonatomic,assign) BOOL tapToResetEnabled;

@property(nonatomic,assign) CGFloat minimumScale;
@property(nonatomic,assign) CGFloat maximumScale;
@property(nonatomic,assign) BOOL checkBounds;

@end
