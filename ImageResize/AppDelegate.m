//
//  AppDelegate.m
//  iMessageScript
//
//  Created by ericyang on 14/10/25.
//  Copyright (c) 2014年 Metasolo. All rights reserved.
//

#import "AppDelegate.h"
#import "PubHeader.h"
#import "NSImage+MGCropExtensions.h"


#define CORRECT_FILE_NAME @"ey_imessage_is.txt"
#define WRONG_FILE_NAME @"ey_imessage_is_not.txt"


#define KEY_UUID @"2014-10-27 16:22:26-86820DEC-DFEC-97AD-F95C-7186BAAD1D95"
enum{
    
    TAG_REQUEST_UUIDLIST=2001,

};


@interface AppDelegate ()
@property (weak) IBOutlet NSTextField *lbUUID;
@property (weak) IBOutlet NSTextFieldCell *tfMsg;

@property (weak) IBOutlet NSTextField *tfSrcPath;
@property (weak) IBOutlet NSTextField *tfdirPath;
@property (weak) IBOutlet NSTextField *tfSize;
- (IBAction)run:(id)sender;
- (IBAction)chooseSrcFile:(id)sender;
- (IBAction)chooseDirFile:(id)sender;
- (IBAction)reset:(id)sender;

@property (weak) IBOutlet NSWindow *window;
@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    // Insert code here to initialize your application

    _lbUUID.stringValue=KEY_UUID;
    [_lbUUID setHidden:YES];
}

- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}

- (IBAction)run:(id)sender {
    {
        NSString* path=[NSString stringWithFormat:@"%@/%@",_tfdirPath.stringValue,CORRECT_FILE_NAME];
        if ([[NSFileManager defaultManager] fileExistsAtPath:path]) {
            [[NSFileManager defaultManager] removeItemAtPath:path error:0];
        }
    }
    {
        NSString* path=[NSString stringWithFormat:@"%@/%@",_tfdirPath.stringValue,WRONG_FILE_NAME];
        if ([[NSFileManager defaultManager] fileExistsAtPath:path]) {
            [[NSFileManager defaultManager] removeItemAtPath:path error:0];
        }
        
    }
    
    
    if (_tfSrcPath.stringValue!=nil
        && ![@"" isEqualToString:_tfSrcPath.stringValue]) {
       
        if (_tfSize.stringValue==nil
            || [@"" isEqualToString:_tfSize.stringValue]) {
            return;
        }
        NSArray* sizes=[_tfSize.stringValue componentsSeparatedByString:@","];
        
       
        for (NSString* num in sizes) {
            NSImage* sourceImage=[[NSImage alloc]initWithContentsOfFile:_tfSrcPath.stringValue];
            
            //FIXME
            // widht and height must divided by 2.0, or we will get @2x size
            NSSize imageSize = sourceImage.size;
            CGFloat ratio = num.intValue / imageSize.width;
            NSSize targetSize = NSMakeSize(num.intValue/2.0, imageSize.height * ratio / 2.0);
            NSImage* resultImg = [sourceImage imageToFitSize:targetSize method:MGImageResizeScale];
            
            //save as jpeg
//            NSData *imageData = [resultImg  TIFFRepresentation];
//            NSBitmapImageRep *imageRep = [NSBitmapImageRep imageRepWithData:imageData];
//            NSDictionary *imageProps = [NSDictionary dictionaryWithObject:[NSNumber numberWithFloat:0.9] forKey:NSImageCompressionFactor];
//            imageData = [imageRep representationUsingType:NSJPEGFileType properties:imageProps];
//            [imageData writeToFile:[NSString stringWithFormat:@"%@/Icon-%d.jpg",_tfdirPath.stringValue,num.intValue] atomically:NO];
            
            //save as png
            CGImageRef cgRef = [resultImg CGImageForProposedRect:NULL  context:nil  hints:nil];
            NSBitmapImageRep *newRep = [[NSBitmapImageRep alloc] initWithCGImage:cgRef];
            [newRep setSize:[resultImg size]];   // if you want the same resolution
            NSData *pngData = [newRep representationUsingType:NSPNGFileType properties:nil];
            [pngData writeToFile:[NSString stringWithFormat:@"%@/Icon-%d.png",_tfdirPath.stringValue,num.intValue] atomically:YES];
        }
        
        
        
       
        
    } else {
        
    }
   
}


- (IBAction)chooseSrcFile:(id)sender {
    // Loop counter.
    int i;
    
    // Create a File Open Dialog class.
    NSOpenPanel* openDlg = [NSOpenPanel openPanel];
    
    
    // Enable options in the dialog.
    [openDlg setCanChooseFiles:YES];
    [openDlg setAllowedFileTypes:@[@"png"]];
    [openDlg setAllowsMultipleSelection:FALSE];
    
    // Display the dialog box.  If the OK pressed,
    // process the files.
    if ( [openDlg runModal] == NSOKButton ) {
        
        // Gets list of all files selected
        NSArray *files = [openDlg URLs];
        
        // Loop through the files and process them.
        for( i = 0; i < [files count]; i++ ) {
            
            // Do something with the filename.
            NSLog(@"src path: %@", [[files objectAtIndex:i] path]);
            [_tfSrcPath setStringValue:[[files objectAtIndex:i] path]];
        }
        
    }
}

- (IBAction)chooseDirFile:(id)sender  {
    
    NSOpenPanel *panel = [NSOpenPanel openPanel];
    NSString *fileName=@"file-dir";
    [panel setMessage:@"Please select a path where to save exported files."];
    [panel setAllowsOtherFileTypes:YES];
    [panel setExtensionHidden:NO];
    [panel setCanCreateDirectories:YES];
    [panel setCanChooseDirectories:YES];
    [panel setCanChooseFiles:NO];
    [panel setNameFieldStringValue:fileName];

    
    [panel beginSheetModalForWindow:self.window completionHandler:^(NSInteger result){
        if (result == NSFileHandlingPanelOKButton) {
            NSArray* urls = [panel URLs];
            for (NSURL *url in urls) {
                [_tfdirPath setStringValue:[url path]];
                NSLog(@"dir path: %@", [url path]);
            }
        }
    }];
}

- (IBAction)reset:(id)sender {
    [_tfSrcPath setStringValue:@""];
    [_tfdirPath setStringValue:@""];
}

@end
