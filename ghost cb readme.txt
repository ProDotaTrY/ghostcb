================================
GHost++ CB (Custom Build) Readme
================================


============
Introduction
============

On top of the commands that are shown in "ghost\readme.txt" there are also commands and features that are added in this custom version.
A lot of the coding has not been actually done by me, but other users from the forums.  I merely insert their code into this public release build.
The SVN Repository is located at http://ghostcb.googlecode.com

========
Commands
========
*** In battle.net (via local chat or whisper at any time):

!emote				repeats anything you say with /me in front of it.

*** In game lobby:

!startn				starts the game immediately with no countdowns or delays.
!start now			alias to !startn

*** In game:


*** In admin game lobby

===================
ghost.cfg additions
===================
### List of countries to allow based on the two-letter country codes
### Don't separate entries with spaces or commas or anything, leave blank or comment out to allow 
### Example: approvedcountries = USCA
bot_approvedcountries = 

### LAN Admins
###  0 - off (default) / 1 - LAN players will be Admins / 2 - LAN players will be Root Admins
bot_lanadmins = 

### Waaagh!TV
###  used for creating 'live' replays
bot_wtv_enabled = 0
bot_wtv_path = C:\Program Files\wc3tv
bot_wtv_observerplayername = Waaagh!TV

====================
map config additions
====================
### Map HCL Rotation
### If you add these three lines to a dota config,
### when autohosted the gamename will be map_gamenamewithmode as long as map_hclfromgamename = 1 and map_validmodes shows a valid mode
### it will display a random mode from map_validmodes as a replacement for $mode$ in game name
map_hclfromgamename = 1
map_validmodes = -arso -apso -rdso -sdso -aremso -apemso
map_gamenamewithmode = Dota 5v5 $mode$ !!!

========
Features
========
- improved motd.txt handling (supports variables: $OWNERNAME$, $GAMENAME$, $HCL$, $VERSION$, $USER$)
- automatically detects the map_type as dota & sets map_matchmakingcategory to dota_elo when loading a DotA map
- blocks battle.net !say commands (ex. !say /squelch user) unless sent from a Root Admin
=======
Credits
=======
I really hope that I have been able to give credit to all those involved in developing this and other versions of GHost++.

-Varlock
-Psionic
-Lucasn
-Strlianc
-Spoofy
-Senkin
-Emmeran
-Vunutus
-disturbed_oc
-AlienLifeForm
-Instinct121
-Fire86

