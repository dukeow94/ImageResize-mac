//
//  PubHeader.h
//  hw8264
//
//  Created by Eric Yang on 13-7-8.
//  Copyright (c) 2013年 Eric Yang. All rights reserved.
//



#ifndef hw8264_PubHeader_h
#define hw8264_PubHeader_h


#define IS_APPSTORE_RELEAES NO //change to 'YES' before release to app store
//#define IS_APPSTORE_RELEAES YES //change to 'YES' before release to app store
//#define IS_TEST_SERVER TRUE //change to 'TRUE/FALSE'
#define IS_TEST_SERVER FALSE //change to 'TRUE/FALSE'

#define KEY_UMENG @"5420f838fd98c51566027350"
#define KEY_WECHAT @"wxbc6ce89f722d820d"
#define KEY_WECHAT_APPSECRET @"28d6f3a052ed7d112c5ebf88a7d54efc"
#define KEY_QQ_ID @"1103103389"
#define KEY_QQ_KEY @"jc93mFSATbHD7cgE"

#define UFK_JPUSH_ALIAS @"UFK_JPUSH_ALIAS"

#define ANIMATION_TIME_BIG_IMAGE 0.3f

#define APPSTORE_LINK @"https://itunes.apple.com/app/8264/id933498480?mt=8"


#define KIND_ID_KEY @"KIND_ID_KEY"
#define KIND_TITLE_KEY  @"KIND_TITLE_KEY"
#define KIND_INFO_KEY  @"KIND_INFO_KEY"
#define KIND_IMG_KEY @"KIND_IMG_KEY"
#define KIND_SUB_KEY @"KIND_SUB_KEY"






//-------begin
#if IS_TEST_SERVER

#define DOMAINLVMALL @"t.7jia2.com"
#define DOMAINLVMALL_IMAGE @"http://tautoimg.7jia2.com"

#else

#define DOMAINLVMALL @"www.7jia2.com"
#define DOMAINLVMALL_IMAGE @"http://autoimg.7jia2.com"

#endif


//-------end



//FONT SIZE------
#define FONT_SIZE_SMALL 14
#define FONT_SIZE_MIDDLE 16
#define FONT_SIZE_LARGE 18
#define FONT_SIZE_SUPER_LARGE 20

//KEY-----------------
/*
 iphone3g  163 ppi
 iPhone5基础分辨率K_SCREEN_WIDTHx568，像素640x1136，@2x 326 ppi
 iPhone6基础分辨率375x667，像素750*1334 ，@2x 分辨率：326 PPI
 iPhone6 Plus基础分辨率414*736，像素1080*1920   @3x， 401 PPI
 */
#define IS_IOS8 ((floor(NSFoundationVersionNumber) > NSFoundationVersionNumber_iOS_7_1))
#define K_SCREEN_HEIGHT ([[UIScreen mainScreen ] bounds ].size.height)
#define K_SCREEN_WIDTH ([[UIScreen mainScreen ] bounds ].size.width)
#define K_NAVIGATION_BAR_HEIGHT (44.0f+20)


#define CLASS_IS_NSARRAY(X) [X isKindOfClass:NSArray.class]
#define CLASS_IS_NSDICTIONARY(X) [X isKindOfClass:NSDictionary.class]

#define APPDELEGATE ((LMAppDelegate*)  [[UIApplication sharedApplication] delegate])
#define NOTIFICATIONCENTER  [NSNotificationCenter defaultCenter]
 #define USERDEFAULTS [NSUserDefaults standardUserDefaults]

#define K_NFC_USERINFO_UPDATE @"K_NFC_USERINFO_UPDATE"
#define K_NFC_ADDRESS_UPDATE @"K_NFC_ADDRESS_UPDATE"
#define K_NFC_ALIPAY_RESULT @"K_NFC_ALIPAY_RESULT"


#define K_NFC_CART_COUNT_CHANGEED_NORMAL @"K_NFC_CART_COUNT_CHANGEED_NORMAL"
#define K_NFC_CART_COUNT_CHANGEED_GROUP @"K_NFC_CART_COUNT_CHANGEED_GROUP"

#define K_NFC_CART_ORDER_STATES_CHANGED @"K_NFC_CART_ORDER_STATES_CHANGED"


#define CACHE_MYTHRAD @"cache_mythrad"
#define CACHE_MYREPLY @"cache_myreply"
#define CACHE_MYFAV @"cache_myfav"
#define CACHE_OFFLINE @"cache_offine"


#define UDF_CRASH_MSG @"UDF_CRASH_MSG"


#define STRATEGY_DIRECTORY @"STRATEGY_DIRECTORY"



#define TAG_CRITIAL_POINT 1000
#define LocalizedString(string) NSLocalizedString(string, @"")
#define PHTOT_LOAD_OFFSET 3
#define REFRESH_DELAY 2
#define K_PRE_LOAD_HEIGHT_BEGIN 568*2
#define K_MIN_LOAD_INTERVAL 1

#define UFK_HAVE_SYNC_DATA_FORUMS @"UFK_HAVE_SYNC_DATA_FORUMS"
#define UFK_HAVE_SYNC_DATA_NEWS @"UFK_HAVE_SYNC_DATA_NEWS"
#define UDF_CURRENT_VERSION @"UDF_CURRENT_VERSION"
#define UDF_CONTENT_FONT @"UDF_CONTENT_FONT"
#define UDF_LAST_CACHE_CLEAR_TIME @"UDF_LAST_CACHE_CLEAR_TIME"
#define UDF_IS_3G_MODEL @"UDF_IS_3G_MODEL"


#define UDF_KINDSLIST_VERSION @"UDF_KINDSLIST_VERSION"

#define UDF_NEW_THREAD_TITLE @"UDF_NEW_THREAD_TITLE"
#define UDF_NEW_THREAD_CONTENT @"UDF_NEW_THREAD_CONTENT"

#define UDF_GUIDE_FIRST_LEFT_VC @"UDF_GUIDE_FIRST_LEFT_VC"
#define UDF_GUIDE_FIRST_STRA_PAGE @"UDF_GUIDE_FIRST_STRA_PAGE"

//#define UDF_OFFLINE_CACHE @"UDF_OFFLINE_CACHE"
//#define UDF_OFFLINE_CACHE_WIFI @"UDF_OFFLINE_CACHE_WIFI"
#define UDF_OFFLINE_CACHE_3G @"UDF_OFFLINE_CACHE_3G"
#define UDF_OFFLINE_CACHE_IMAGE @"UDF_OFFLINE_CACHE_IMAGE"


#define UDF_ACCESS_TOKEN @"UDF_ACCESS_TOKEN"
#define UDF_REFRESH_TOKEN @"UDF_REFRESH_TOKEN"
#define UDF_OPENID @"UDF_OPENID"


#define UDF_LAST_VERIFY_CODE_TIME @"UDF_LAST_VERIFY_CODE_TIME"


/**
 * UDF_CART_COUNT_NORMAL: store the lastest count count
 */
#define UDF_CART_COUNT_NORMAL @"UDF_CART_COUNT_NORMAL"
#define UDF_CART_COUNT_GROUP @"UDF_CART_COUNT_GROUP"

//#define HASLOGIN NO
#define HASLOGIN (![StringUtil isNilOrEmpty:APPDELEGATE.userBean.token])
#define HASADDRESS (APPDELEGATE.userBean.addressBeans.count>0)


#define INDEXPATH_SUBVIEW_TABLEVIEW(subview,tableview)\
({\
CGRect subviewFrame = [subview convertRect:subview.bounds toView:tableview];\
NSIndexPath *indexPath = [tableview indexPathForRowAtPoint:subviewFrame.origin];\
indexPath;\
})\

#define CELL_SUBVIEW_TABLEVIEW(subview,tableview)\
({\
CGRect subviewFrame = [subview convertRect:subview.bounds toView:tableview];\
NSIndexPath *indexPath = [tableview indexPathForRowAtPoint:subviewFrame.origin];\
UITableViewCell *cell=[_tvItems cellForRowAtIndexPath:indexPath];\
cell;\
})\

#define testdismiss {\
[self.navigationController dismissViewControllerAnimated:YES completion:nil];\
return;\
}\

//check and show loginVC and return
#define SHOWLOGINVC \
if (!HASLOGIN) {\
LMLoginVC* vc=[[LMLoginVC alloc]init];\
CoverNavigationViewController* nav =[[CoverNavigationViewController alloc]initWithRootViewController:vc];\
[self.tabBarController presentViewController:nav animated:YES completion:nil];\
return;\
}\
\

#define JSONSTRINGFORMAT(S) [NSString stringWithFormat:@"%@",S]
#define INTTOSTRING(I) [NSString stringWithFormat:@"%d",I]
#define FLOATTOSTRING(F) [NSString stringWithFormat:@"%f",F]
#define BOOLTOSTRING(B) [NSString stringWithFormat:@"%d",B]
#define DOUBLETOSTRING(D) [NSString stringWithFormat:@"%f",D]

#define IS_OFFLINE(tid) [[OfflineCacheService share] hasSyncTBWithTid:tid]

#define STRING_UTF8_TO_GBK(S) ([S stringByAddingPercentEscapesUsingEncoding:CFStringConvertEncodingToNSStringEncoding(kCFStringEncodingGB_18030_2000)])

#define APP_DOCUMENT_PAHT [((NSArray*)NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)) objectAtIndex:0]
#define APP_LIBRARY_PAHT [((NSArray*)NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES)) objectAtIndex:0]

#define UMENG_EVENT(name) [MobClick event:name];

#define Alert(titleText,messageText) \
{\
UIAlertView * alert = [[UIAlertView alloc]\
initWithTitle:titleText \
message:messageText \
delegate:nil \
cancelButtonTitle:@"ok" \
otherButtonTitles:nil];\
\
[alert show];\
alert = nil;\
}\
\

#define Alert2(messageText) \
{\
UIAlertView * alert = [[UIAlertView alloc]\
initWithTitle:nil \
message:messageText \
delegate:nil \
cancelButtonTitle:@"ok" \
otherButtonTitles:nil];\
\
[alert show];\
alert = nil;\
}\
\




//TAG t which 1000<t<2000 means dealing with offset
#define TAG_MAX_REQUEST_OFFSET 2000
#define TAG_MIN_REQUEST_OFFSET 1000

#ifndef DEBUG_LOG
#define DEBUG_LOG
#define LOGERROR NSLog(@"error !!!!!!!!! %s,%d",__FUNCTION__,__LINE__);
#define LOGWARNING NSLog(@"warning %s,%d",__FUNCTION__,__LINE__);
#define LOGERRORMSG(msg) NSLog(@"error:%@ %s,%d",msg,__FUNCTION__,__LINE__);
#define LOGLINE NSLog(@"info %s,%d",__FUNCTION__,__LINE__);
#define LOGINFO(format,value)  NSLog([NSString stringWithFormat:@"%@ ; info %%s,%%d",format],value,__FUNCTION__,__LINE__);
#define LOGTIME NSLog(@"%f %s,%d",[[NSDate date]timeIntervalSince1970],__FUNCTION__,__LINE__);

#define LOGNOTHING(format,value)
#endif

#define REQUESTFAILED \
- (void)requestFailed:(ASIHTTPRequest *)request{\
LOGINFO(@"rquest error tag:%d", request.tag)\
    [[DialogUtil share]unshowLoading];\
    [APPDELEGATE checkNet];\
    LOGERROR\
}\

#define REQUESTFAILED_OFFSTE \
- (void)requestFailed:(ASIHTTPRequest *)request{\
LOGINFO(@"rquest error tag:%d", request.tag)\
[[DialogUtil share]unshowLoading];\
RESET_OFFSET(request)\
[APPDELEGATE checkNet];\
}\

#define REQUESTFAILED_OFFSTE_BLOCK(netErrorBlock) \
- (void)requestFailed:(ASIHTTPRequest *)request{\
LOGINFO(@"rquest error tag:%d", request.tag)\
[[DialogUtil share]unshowLoading];\
RESET_OFFSET(request)\
[APPDELEGATE checkNetCallback:netErrorBlock request:request];\
LOGERROR\
}\

#define REQUEST_IS_LIST (request.tag<TAG_MAX_REQUEST_OFFSET && request.tag>TAG_MIN_REQUEST_OFFSET)

#define RESET_OFFSET(REQUEST)\
if (request.tag<TAG_MAX_REQUEST_OFFSET && request.tag>TAG_MIN_REQUEST_OFFSET) {\
    [self requestOffsetFailed];\
}\

#define DEAL_REQUEST_ERROR(REQUEST) \
NSString* error=[result objectForKey:@"error"];\
if (error.intValue!=0) {\
    NSLog(@"msg:%@",[result objectForKey:@"msg"]);\
    return;\
}\

#define DEAL_REQUEST_ERROR_HUD(REQUEST) \
NSString* error=[result objectForKey:@"error"];\
if (error.intValue!=0) {\
NSLog(@"msg:%@",[result objectForKey:@"msg"]);\
[[DialogUtil share]showHUD:APPDELEGATE.window image:[UIImage imageNamed:@"status_error"] text:[NSString stringWithFormat:@"%@",[result objectForKey:@"msg"]]];\
return;\
}\


#define DEAL_REQUEST_ERROR_OFFSET(REQUEST) \
NSString* error=[result objectForKey:@"error"];\
if (error.intValue!=0) {\
RESET_OFFSET(REQUEST)\
NSLog(@"msg:%@",[result objectForKey:@"msg"]);\
return;\
}\

#define DEAL_REQUEST_ERROR_OFFSET_HUD(REQUEST) \
NSString* error=[result objectForKey:@"error"];\
if (error.intValue!=0) {\
RESET_OFFSET(REQUEST)\
NSLog(@"msg:%@",[result objectForKey:@"msg"]);\
[[DialogUtil share]showHUD:APPDELEGATE.window image:[UIImage imageNamed:@"status_error"] text:[result objectForKey:@"msg"]];\
return;\
}\

#define DEAL_REQUEST_ERROR_OFFSET_HUD_ERRORCALLFUNCTION(REQUEST,FUNCTION) \
NSString* error=[result objectForKey:@"error"];\
if (error.intValue!=0) {\
FUNCTION;\
RESET_OFFSET(REQUEST)\
NSLog(@"msg:%@",[result objectForKey:@"msg"]);\
[[DialogUtil share]showHUD:APPDELEGATE.window image:[UIImage imageNamed:@"status_error"] text:[result objectForKey:@"msg"]];\
return;\
}\




/* color helper */
#define COLORRGBA(c,a) [UIColor colorWithRed:((c>>16)&0xFF)/255.0	\
green:((c>>8)&0xFF)/255.0	\
blue:(c&0xFF)/255.0         \
alpha:a]
#define COLORRGB(c)    [UIColor colorWithRed:((c>>16)&0xFF)/255.0	\
green:((c>>8)&0xFF)/255.0	\
blue:(c&0xFF)/255.0         \
alpha:1.0]




#define IS_SAME_YEAR(TIME) ([StringUtil isSameTime:TIME format:@"yyyy"])

#define FORMATE_DOUBLE_DATE_ABSOLUTE(sDouble)  [StringUtil doubleTimeFormate:sDouble ]

#define FORMATE_DOUBLE_DATE_RELATIVE(sDouble) ({\
NSString* timeString=nil;\
double timeFloat=sDouble;\
double now=[[NSDate date]timeIntervalSince1970];\
double diff=now-timeFloat;\
if (diff<60*1) {\
    timeString=@"刚刚";\
} else if (diff<60*60){\
    timeString=[NSString stringWithFormat:@"%d分钟前",((int)diff)/60];\
} else if (diff<60*60*24){\
    timeString=[NSString stringWithFormat:@"%d小时前",((int)diff)/(60*60)];\
} else if (diff<60*60*24*7){\
    int days=diff/(60*60*24); \
    if(days==1){\
        timeString=@"昨天";\
    }else if(days==2){\
        timeString=@"前天";\
    }\
    timeString=[NSString stringWithFormat:@"%d天前",days];\
} else if (IS_SAME_YEAR(timeFloat)){\
    timeString=[StringUtil doubleTimeFormate:timeFloat withFormat:@"MM-dd"];\
}else{\
    timeString=[StringUtil doubleTimeFormate:timeFloat];\
}\
timeString;})


#define REMOVE_BREAKLINE(value)  ({\
{\
value = [[value componentsSeparatedByCharactersInSet:[NSCharacterSet whitespaceCharacterSet]] componentsJoinedByString:@">"];\
NSRegularExpression *regex = [NSRegularExpression regularExpressionWithPattern:@">+" options:0 error:NULL];\
value = [regex stringByReplacingMatchesInString:value options:0 range:NSMakeRange(0, [value length]) withTemplate:@""];\
}\
{\
    value = [[value componentsSeparatedByCharactersInSet:[NSCharacterSet newlineCharacterSet]] componentsJoinedByString:@">"];\
    NSRegularExpression *regex = [NSRegularExpression regularExpressionWithPattern:@">+" options:0 error:NULL];\
    value = [regex stringByReplacingMatchesInString:value options:0 range:NSMakeRange(0, [value length]) withTemplate:@" "];\
}\
value;\
})\

#define GENDERID2TXT(GID)  ({\
NSString* gender;\
switch (GID) {\
case 0:\
gender=@"保密";\
break;\
case 1:\
gender=@"男";\
break;\
case 2:\
gender=@"女";\
break;\
}\
gender;\
})


#define SHOW_PHOTO_BROWSER_ANIMATION(SHOWFUNCTION,SELFVIEW) \
{\
CATransition *transition = [CATransition animation];\
transition.duration = 0.3;\
transition.timingFunction = UIViewAnimationCurveEaseInOut;\
transition.type = kCATransitionMoveIn;\
transition.subtype = kCATransitionFromRight;\
[SELFVIEW.view.window.layer addAnimation:transition forKey:nil];\
SHOWFUNCTION;\
}\

#define DISMISS_PHOTO_BROWSER_ANIMATION(DISMISSFUNCTION,SELFVIEW) \
{\
CATransition *transition = [CATransition animation];\
transition.delegate = self;\
transition.duration = 0.3;\
transition.timingFunction = UIViewAnimationCurveEaseInOut;\
transition.type = kCATransitionReveal;\
transition.subtype = kCATransitionFromLeft;\
[SELFVIEW.view.window.layer addAnimation:transition forKey:nil];\
DISMISSFUNCTION;\
}\


#define PRESENT_VC_LIKE_PUSH(SHOWFUNCTION) \
{\
CATransition *transition = [CATransition animation];\
transition.duration = 0.3;\
transition.timingFunction = UIViewAnimationCurveEaseInOut;\
transition.type = kCATransitionMoveIn;\
transition.subtype = kCATransitionFromRight;\
[self.view.window.layer addAnimation:transition forKey:nil];\
SHOWFUNCTION;\
}\


#define DISMISS_VC_LIKE_POP(SHOWFUNCTION) \
{\
CATransition *transition = [CATransition animation];\
transition.delegate = self;\
transition.duration = 0.3;\
transition.type = kCATransitionReveal;\
transition.subtype = kCATransitionFromLeft;\
[self.view.window.layer addAnimation:transition forKey:nil];\
SHOWFUNCTION;\
}\

typedef enum{
    T_USER=1,
    T_TITLE,
    T_LASTUPDATE,
    T_ITEM,
}MenuType;

typedef enum{
    FORUM_BBS=10,
    FORUM_NEWS,
    FORUM_SUBJECT,
} FORUM_TYPE;


#define   DDMENUCONTROLLER ((DDMenuController*)((AppDelegate*)[[UIApplication sharedApplication] delegate]).viewController)

//=======FOR DEBUG
//*/
#define HOST @"192.168.1.188"
/*/
 #define HOST @"mobile.8264.com"
//*/

#define HOST_URL_PARSE(URL) [NSString stringWithFormat:URL,HOST]


#define FONTSIZE(s) [UIFont fontWithName:@"HiraginoSansGB-W3" size:(s)]
#define SYSTEMFONTSIZE(x) [UIFont systemFontOfSize:x]

#endif
