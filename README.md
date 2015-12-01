ZJTPropertyHelper
--
`ZJTPropertyHelper` make property support NSUserDefaults storage with two lines of code.


## Usage

### PropertyManager



#### Extends from `ZJTPropertyHelper`,
For example, Define two properties `Logined`,  `Text`.

```objective-c
#import "ZJTPropertyHelper.h"

@interface PropertyManager :ZJTPropertyHelper

/**
 *  @author PatrickCoin, 15-11-30 18:11:52
 *
 *  BOOL type
 */
BOOL_PROP_DEF(Logined)

/**
 *  @author PatrickCoin, 15-11-30 18:11:05
 *
 *  NSString type
 */
STRING_PROP_DEF(Text)

+(instancetype)sharedIncetance;

@end
```

#### implementation of `PropertyManager`,
```objective-c
@implementation PropertyManager

/**
 *  @author PatrickCoin, 15-12-01 10:12:12
 *
 *  implementation of Logined
 */
BOOL_PROP_IMPL(Logined)

/**
 *  @author PatrickCoin, 15-12-01 10:12:12
 *
 *  implementation of Text
 */
STRING_PROP_IMPL(Text)

+(instancetype)sharedIncetance
{
    static PropertyManager *incetance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^
                  {
                      incetance = [[PropertyManager alloc] init];
                  });
    
    return incetance;
}

@end
```
#### Example
```objective-c
@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self readText];
}

-(void)readText
{
    NSString *text = [[PropertyManager sharedIncetance] getText];
    
    if (text && text.length) {
        self.label.text = text;
    }
}

- (IBAction)saveData:(id)sender {
    NSString *text = self.textFiled.text;
    if (text && text.length) {
        [[PropertyManager sharedIncetance] setText:text];
        [self readText];
    }
}

@end
```
