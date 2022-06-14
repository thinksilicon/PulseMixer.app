# Description
<div style="float:left;margin-right:10px;margin-bottom:10px;" >
![screenshot](screenshot.png)
</div>
PulseMixer.app is a mixer utility for Linux systems with PulseAudio.
It is designed to be docked in Window Maker (and other wms). This utility has
three volume controllers:
- 1st: Default Audio SINK (your speakers)
- 2nd: Default Audio SOURCE (your microphone)
- 3rd: Any application that matches a search pattern (default Firefox)

The mixer will automaticaly chose the last added instance of the
application (Firefox) as this is most likely emitting the noise.

There is also wheel mouse support.
The whole GUI and command parsing was taken from AlsaMixer.app and
PulseClient was taken from Ponymix. Together this makes the
Mixer ready to run with modern Linux distributions, allowing
automaticaly switch over to new audio sinks, like bluetooth headsets.


# Hints
- Error led:
	If the led on Mixer.app is red an error message has 
	been printed to stderr and something is not working 
	correctly. If the led is green everything is working ok.
	(Error led doesn't work in PulseMixer.app, TODO)

- Mute:
	Right click on a volume controller to mute the sound
	source. The button will then have a red led in one corner.
	Right click again to restore the volume. If a muted sound
	source is modified by another application Mixer.app will 
	automaticaly release its muted state.

- Wheel mouse:
	If you have a wheel mouse (where the wheel is configured as 
	Button4 and Button5) you can control the volume by just moving
	the mouse over Mixer.app and roll the wheel up and down. Use 
	the command line option -w to specify which slider that should 
	react to the wheel movement.

- Label:
	If you run multiple instances of PulseMixer.app you might want
	to be able to tell them apart. This can easily be done
	by setting a label to each one of them. By using the -l
	option you can add a little text label at the bottom of
	the mixer.

- Save volume settings:
	Use the option -S (and -f <file>) if you want the volume 
	settings to be saved when PulseMixer.app exits, and then 
	-L to be loaded again when PulseMixer.app is started the next time.
	When not using -f the settings are saved in/loaded from
	~/GNUstep/Defaults/PulseMixer. Use the -f <file> option
	if you want to use a different file.
	(TODO: mute states aren't saved/loaded)

- Configurable middle click:
	By default, when you middle click anywhere inside application
	window, app tries to load default mixer setting from default
	or explicitly configured (-f) file. If file doesn't exist,
	nothing happens.
	You can also configure PulseMixer.app to run command (i.e.
	better mixer) on middle click by using -e <command> option.

# Bugs
I'm sad to say that this application is a case of "works for me".
Feel free to fork and apply your own changes. I'm also happy to
merge any pull requests. I just can't provide any support beyond.


# Special thanks to
- Petr Hlavka <xhlavk00@stud.fit.vutbr.cz> - original author of AlsaMixer.app
- Dave Reisner <dreisner@archlinux.org> and Simon Gomizelj <simongmzlj@gmail.com> - Ponymix
- Per Liden <per@fukt.bth.se> - original author of Mixer.app
- David Sauer <davids@iol.cz>
- Theo Schlossnagle <theo@omniti.com>
- Alban Hertroys <dalroi@wit401310.student.utwente.nl>


# Copyright
- PulseMixer.app 2022, Thinksilicon
- AlsaMixer.app, 2004, Petr Hlavka
- Mixer.app is copyright (c) 1998-2002 by Per Liden and is licensed through the GNU General Public License. Read the COPYING file for the complete license.
- PulseClient was taken from Ponymix by Dave Reisner <dreisner@archlinux.org> and Simon Gomizelj <simongmzlj@gmail.com> https://github.com/falconindy/ponymix/
