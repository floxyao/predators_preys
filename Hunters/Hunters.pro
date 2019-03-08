TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

#LIBS += -L "C:\Users\admin\Documents\SFML\SFML-2.3.2\lib"
#LIBS += -L "C:\Users\admin\Documents\SFML\SFML-2.3.2\bin"
#LIBS += -L"../../SFML-2.3.2/lib"
#LIBS += -L"../../SFML-2.3.2/bin"
#LIBS += -L"..\..\SFML-2.3.2\lib"
#LIBS += -L"..\..\SFML-2.3.2\bin"

LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

INCLUDEPATH += "/usr/local/include"
DEPENDPATH += "/usr/local/include"

#INCLUDEPATH += "C:\Users\admin\Documents\SFML\SFML-2.3.2\include"
#DEPENDPATH += "C:\Users\admin\Documents\SFML\SFML-2.3.2\include"
#INCLUDEPATH += "..\..\SFML-2.3.2\include"
#DEPENDPATH += "..\..\SFML-2.3.2\include"

SOURCES += main.cpp\
    game.cpp

HEADERS += \
    grid.h \
    creature.h \
    hunter.h \
    constants.h \
    prey.h \
    wall.h \
    random.h \
    game.h
