//	Copyright (c) 2009 Stephen Deken
//	All rights reserved.
// 
//	Redistribution and use in source and binary forms, with or without modification,
//	are permitted provided that the following conditions are met:
//
//	*	Redistributions of source code must retain the above copyright notice, this
//		list of conditions and the following disclaimer.
//	*	Redistributions in binary form must reproduce the above copyright notice,
//		this list of conditions and the following disclaimer in the documentation
//		and/or other materials provided with the distribution.
//	*	Neither the name KeyCastr nor the names of its contributors may be used to
//		endorse or promote products derived from this software without specific
//		prior written permission.
//
//	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//	AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
//	WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
//	IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
//	INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
//	BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//	DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
//	LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
//	OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
//	ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.



#import <Cocoa/Cocoa.h>
#import "KCVisualizer.h"
#import "KCKeyboardTap.h"
#import "KCKeystroke.h"
#import "ShortcutRecorder/ShortcutRecorder.h"

@class KCPrefsWindowController;

/** Application Controller


*/
@interface KCAppController : NSObject
{
	IBOutlet NSMenu* statusMenu;
	IBOutlet NSWindow* aboutWindow;
	IBOutlet NSWindow* preferencesWindow;
	IBOutlet KCPrefsWindowController* prefsWindowController;
	NSWindow* visualizerWindow;
	NSStatusItem* statusItem;
	id<KCVisualizer> currentVisualizer;
	IBOutlet SRRecorderControl* shortcutRecorder;
	IBOutlet NSMenuItem* statusShortcutItem;
	IBOutlet NSMenuItem* dockShortcutItem;
	BOOL _isCapturing;
	BOOL _allowToggle;
	int _startupIconPreference;
	BOOL _displayedRestartAlertPanel;
}

-(IBAction) orderFrontKeyCastrAboutPanel:(id)sender;
-(IBAction) orderFrontKeyCastrPreferencesPanel:(id)sender;
-(IBAction) toggleRecording:(id)sender;
-(IBAction) pretendToDoSomethingImportant:(id)sender;
-(IBAction) changeIconPreference:(id)sender;

-(BOOL) isCapturing;
-(void) setIsCapturing:(BOOL)isCapturing;
-(void) registerVisualizers;

-(NSStatusItem*) createStatusItem;

-(NSArray*) availableVisualizerNames;

-(NSString*) currentVisualizerName;
-(void) setCurrentVisualizerName:(NSString*)visualizerName;

-(id<KCVisualizer>) currentVisualizer;
-(void) setCurrentVisualizer:(id<KCVisualizer>)visualizer;

-(void) keyboardTap:(KCKeyboardTap*)tap noteKeystroke:(KCKeystroke*)keystroke;
-(void) keyboardTap:(KCKeyboardTap*)tap noteFlagsChanged:(uint32_t)flags;

@end
