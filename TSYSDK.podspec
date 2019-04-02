Pod::Spec.new do |s|

    #名称
    s.name         = 'TSYSDK'

    #版本号
    s.version      = '2.2.6'

    #许可证
    s.license      = { :type => 'Copyright', :text => 'TSY Inc. 2019' }

    #项目主页地址
    s.homepage     = 'https://github.com/TSY-SDK/TSYSDK'

    #作者
    s.authors      = { '陈红' => '971063910@qq.com' }

    #简介
    s.summary      = '淘手游支付SDK.'

    #项目的地址 （注意这里的tag位置，可以自己写也可以直接用s.version，但是与s.version一定要统一）
    s.source       = { :git => 'https://github.com/TSY-SDK/TSYSDK.git', :tag => s.version }

    #支持最小系统版本
    s.platform = :ios, '9.0'

    #需要包含的源文件
s.source_files = 'TSYSDK.framework/Headers/*.{h}'
#s.source_files = 'TSYSDK/**/**/*.{h,m,mm}'
    #你的SDK路径
    s.vendored_frameworks = 'TSYSDK.framework'

    #SDK头文件路径
    s.public_header_files = 'TSYSDK.framework/Headers/*.{h}'
    #s.public_header_files = '**/**/*.{h}'
    #依赖库
    s.libraries = 'c++','z'
    s.xcconfig     = {'OTHER_LDFLAGS' => '-ObjC', 'GCC_PREPROCESSOR_DEFINITIONS' => 'ENABLE_LITE=1'}
    #依赖库
    s.frameworks = 'Security', 'SystemConfiguration' 'SystemConfiguration', 'CoreTelephony' 'QuartzCore', 'CoreText' 'CoreGraphics' 'CFNetwork', 'CoreMotion' 'JavaScriptCore'
    #s.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/user/include/libxml2" }
    s.resource = 'TSYSDKBundle'
end
