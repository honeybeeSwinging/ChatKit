//
//  UpLoadFileHelper.h
//  KeyBoardView
//
//  Created by 余强 on 16/3/28.

//

#import <Foundation/Foundation.h>
#import <AFNetworking.h>
#import "ChatHelp.h"




@class FileConfig;

@interface UpLoadFileHelper : NSObject



+ (instancetype)helper;

/**
 *  @brief 监听上传进度
 *
 *  @param files               文件模型
 *  @param progressHandler     <#progressHandler description#>
 *  @param completion          <#completion description#>
 *  @param failure             <#failure description#>
 */

- (void)uploadFiles:(FileConfig *)files
           progress:(progressBlock)progressHandler
         completion:(void(^)(id responseObject))completion
            failure:(void(^)(NSError *error))failure;


@end




#pragma mark -- FileConfig

/**
 *  @brief 用来封装上文件数据的模型类
 */
@interface FileConfig :NSObject


/**
 *  @brief url
 */
@property (nonatomic, strong) NSString *url;

/**
 *  @brief 文件数据:可为url或data
 */
@property (nonatomic, strong) NSArray *fileDatas;

/**
 *  @brief 服务器接收参数
 */
@property (nonatomic, copy) NSString *serverName;


/**
 *  @brief 上传文件名:可不传
 */
@property (nonatomic, copy) NSArray *fileNames;

/**
 *  @brief 文件类型
 */
@property (nonatomic, copy) NSString *mimeType;


/**
 *  @brief 上传参数
 */
@property (nonatomic, copy) NSDictionary *parameter;


+ (instancetype)fileConfigWithUrl:(NSString *)url
                         fileData:(NSArray *)fileDatas
                        serveName:(NSString *)serveName
                         fileName:(NSArray *)fileNames
                         mimeType:(NSString *)mimeType;

- (instancetype)initWithUrl:(NSString *)url
                   fileData:(NSArray *)fileDatas
                  serveName:(NSString *)serveName
                  fileNames:(NSArray *)fileNames
                   mimeType:(NSString *)mimeType;


@end
