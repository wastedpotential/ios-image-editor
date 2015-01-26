iOS Image Editor View
================

A iOS View for image cropping. An alternative to the UIImagePickerController editor with extended features and flexibility. 

This is essentially a minor rework of HFImageEditor to overcome some things I found annoying. This version is a subclass of UIView, eliminating the HFImageEditorViewController which allows more flexibility in implementation. It also allows standard UIView mods, such as layer.masksToBounds and layer.cornerRadius. WPImageEditorView will not crash if the sourceImage is nil/null. output is auto-cropped to WPImageEditorView bounds.



Features
--------

* Full image resolution
* Unlimited pan, zoom and rotation
* Zoom and rotation centered on touch area
* Double tap to reset
* Plug-in your own interface


Usage
-----

```objective-c
WPImageEditorView *imageEditor = [[WPImageEditorView alloc] initWithFrame: CGRectMake(10, 80, 300, 300)];

imageEditor.sourceImage = image;
    ...
}
```

Configuration Properties
----------

#### sourceImage
The full resolution UIImage to crop

#### previewImage

For images larger than <code> maxPreviewSize</code> wide or <code> maxPreviewSize</code> height, the image editor will create a preview image before the view is shown. If a preview is already available you can get a faster transition by setting the preview propety. For instance, if the image was fetched using the UIImagePickerController:
<code>
UIImage *image =  [info objectForKey:UIImagePickerControllerOriginalImage];
NSURL *assetURL = [info objectForKey:UIImagePickerControllerReferenceURL];

[self.library assetForURL:assetURL resultBlock:^(ALAsset *asset) {
    UIImage *preview = [UIImage imageWithCGImage:[asset aspectRatioThumbnail]];
HFImageEditorViewController *imageEditor = [[HFImageEditorViewController alloc] 
    initWithNibName:@"DemoImageEditor" bundle:nil];
    self.imageEditor.sourceImage = image;
    self.imageEditor.previewImage = preview;        
...
} failureBlock:^(NSError *error) {
    NSLog(@"Failed to get asset from library");
}];
</code>

#### maxPreviewSize
The maximum width or height of the previewImage. By default, this is set to 1024. You can change this as needed for performance. 

Note that the maximum previewImage size will always be limited to 2x the largest dimension of the image editor view. This property can be used to further limit the previewImage size on large image editor views.

#### minimumScale, maximumScale
The bounds for image scaling. If not defined, image zoom is unlimited.

#### checkBounds
Set to true to bound the image transform so that the image always fills the image editor view.

#### panEnabled, rotateEnabled, scaleEnabled, tapToResetEnabled
BOOL property to enable/disable specific gestures

Output Properties
----------

####croppedImage
Returns a UIImage cropped to the bounds of the WPImageEditorView.


Interface
---------
The simplest usage is by adding a UIView to your own xib or storyboard.
 
* Set <code>WPImageEditorView</code> (or subclass) as the UIView's custom class


License
---------
ios-image-editor is available under the MIT license. See the LICENSE file for more info.
