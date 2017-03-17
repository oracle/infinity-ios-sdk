Pod::Spec.new do |s|
  s.name         = "Webtrends-SDK"
  s.version      = "3.2.5"
  s.summary      = "The mobile SDK for Webtrends Analytics and Webtrends Optimize"
  s.license      = 'COMMERCIAL'
  s.homepage     = "http://webtrends.com"
  s.author             = { "Sam Ingle" => "Sam.Ingle@webtrends.com",
                           "Blake Clough" => "Blake.Clough@webtrends.com",
                           "John Park" => "John.Park@webtrends.com",
                           "Claudine Morales" => "Claudine.Morales@webtrends.com"}
  
  s.ios.deployment_target = "8.0"
  s.ios.frameworks = "Foundation", "UIKit", "SystemConfiguration", "Security", "CoreTelephony", "WebKit"
  
  s.source       = { :git => "https://github.com/webtrends/ios-sdk.git", :tag => s.version.to_s }

  s.subspec 'Watch' do |watch|
    watch.source_files = "WatchHeaders", "WatchHeaders/**/*.h"
    watch.vendored_library = "libWebtrendsWatchSDK.a"
    watch.watchos.deployment_target = "2.0"
  end

  s.subspec 'Core' do |core|
    core.source_files  = "Headers", "Headers/**/*.h"
    core.exclude_files = "Headers/Exclude"
    core.resources = "SharedAssets/*"

    core.libraries = "z","sqlite3" #Zlib for gzip, sqlite3 for event store
    core.vendored_library = "libWebtrendsSDK.a"
  end

  s.subspec 'Optimize' do |optimize|
    optimize.source_files  = "Headers", "Headers/**/*.h"
    optimize.exclude_files = "Headers/Exclude"
    optimize.resources = "SharedAssets/*"
    optimize.dependency 'Webtrends-SDK/Core', '~>' + s.version.to_s
    optimize.libraries = "sqlite3" # sqlite3 for db
    optimize.vendored_library = "libOptimizeSDK.a"
  end
end
