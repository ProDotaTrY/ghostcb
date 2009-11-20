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


*** In game lobby:

!startn				starts the game immediately with no countdowns or delays.

*** In game:


*** In admin game lobby

===================
ghost.cfg additions
===================
### List of countries to allow based on the two-letter country codes
### Don't separate entries with spaces or commas or anything, leave blank or comment out to allow 
### Example: approvedcountries = USCA
bot_approvedcountries = 

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

