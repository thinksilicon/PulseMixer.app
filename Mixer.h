//
//  Mixer.app
// 
//  Copyright (c) 1998-2002 Per Liden
// 
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, 
//  USA.
//

#ifndef _MIXER_H_
#define _MIXER_H_

#include "PMixer/pulse.h"

#include <X11/Xlib.h>

#define APPNAME		(char *) "PulseMixer.app"
#define VERSION		(char *) "0.1"
#define INSTANCENAME	(char *) "pulsemixer_app"
#define CLASSNAME	(char *) "PulseMixer_app"
#define SETTINGS        "/GNUstep/Defaults/PulseMixer"
#define MAX_COMMAND_LENGTH	512

#define LABEL_X		4
#define LABEL_Y		54
#define LABEL_FONT	"-*-helvetica-medium-r-*-*-8-*-*-*-*-*-*-*"

#define LED_X		57
#define LED_Y		59
#define BUTTON_MIN	45
#define BUTTON_MAX	6

class Mixer 
{
public:
   Mixer(int argc, char** argv);
   ~Mixer() {};
   void run();
   void saveVolumeSettings();
   void GetProfile();
   int GetInputSinkDevice();

private:
   void init_mixer( char* card );
   void tryHelp(char* appname);
   void showHelp();
   void checkArgument(char** argv, int argc, int index);
   void showErrorLed();
   void findMixerDevice();
   void getVolume();
   void setVolume(int button, int volume);
   void toggleMute(int button);
   void setButtonType(int button);
   void setButtonPosition(int button, int position);
   void setButtonPositionRelative(int button, int relativePosition);
   void loadVolumeSettings();

   Display* mDisplay;
   Window   mRoot;
   Window   mAppWin;
   Window   mIconWin;
   Window   mButton[3];
   char*    mMixerDevice;
   char*    mInstanceName;
   char*    mLabelText;
   char*    mSettingsFile;
   char*    mCommand;
   char*    card;
   int      mError;
   int      mVolumeSource[3];
   int      mVolume[3];
   int      mVolumePos[3];
   int      mVolumeMute[3];
   int      mWheelButton;
   bool	    mSaveSettings;
   bool	    mLoadSettings;
   PulseClient* ponymix;
//   AMixer*  aMixer;
};

#endif
