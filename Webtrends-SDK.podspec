Pod::Spec.new do |s|
  s.name         = "Webtrends-SDK"
  s.version      = "3.0.0"
  s.summary      = "The data collection SDK for Webtrends"
  s.license      = 'COMMERCIAL'
  s.homepage     = "http://webtrends.com"
  s.author             = { "Sam Ingle" => "Sam.Ingle@webtrends.com",
                           "Blake Clough" => "Blake.Clough@webtrends.com",
                           "John Park" => "John.Park@webtrends.com",
                           "Claudine Morales" => "Claudine.Morales@webtrends.com"}
  
  s.ios.deployment_target = "7.0"
  s.ios.frameworks = "Foundation", "UIKit", "CoreData", "SystemConfiguration", "Security", "CoreTelephony"
  
  s.source       = { :git => "https://github.com/webtrends/ios-sdk.git", :tag => "3.0.0" }

  s.subspec 'Watch' do |watch|
    watch.source_files = "WatchHeaders", "WatchHeaders/**/*.h"
    watch.vendored_library = "libWebtrendsWatchKitSDK.a"
  end

  s.subspec 'Core' do |core|
    core.source_files  = "Headers", "Headers/**/*.h"
    core.exclude_files = "Headers/Exclude"
    core.resources = "SharedAssets/*"

    core.libraries = "z","sqlite3" #Zlib for gzip, sqlite3 for event store
    core.vendored_library = "libWebtrendsSDK.a"
  end
end
