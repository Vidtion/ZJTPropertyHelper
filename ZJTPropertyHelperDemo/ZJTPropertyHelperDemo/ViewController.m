//
//  ViewController.m
//  ZJTPropertyHelperDemo
//
//  Created by coin on 11/30/15.
//  Copyright © 2015 ZJTSoft. All rights reserved.
//

#import "ViewController.h"
#import "PropertyManager.h"

@interface ViewController ()

@end

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
