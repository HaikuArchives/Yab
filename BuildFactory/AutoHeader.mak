##
## yab Haiku BuildFactory Makefile
##
## (c) Jan Bungeroth 2009 - 2011
## Artistic License. 
##

##
## Haiku stuff
##
HAIKUTAB = YabTabView.o
HAIKUOPT = -DHAIKU

##
## Use our own column list view
## 
COLUMN = column/ColumnListView.o

##
## enable debug
##
# DBG = -g 
# 

##
## enable optimization
##
OPT = -O
#

##
## Libraries
##
LIBPATH = -L/boot/home/config/lib  
LIB = -lncurses -lbe -lroot -ltranslation -ltracker -lmedia -llocale -lz

