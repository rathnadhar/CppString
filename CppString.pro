TARGET = cppstring
CONFIG -= qt
TEMPLATE = lib
DEFINES += CPPSTRING_LIBRARY
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#-- Ensure that debug build and release build are in different directories
# the debug and release directives  MUST BE IN LOWER CASE!!!
CONFIG(debug, debug|release) {
    DESTDIR = $$TARGET/debug
}
CONFIG(release, debug|release) {
    DESTDIR = $$TARGET/release
}

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.u


SOURCES += \
    src/cppstring.cpp

HEADERS += \
    include/cppstring_global.h \
    include/cppstring.h

# Default rules for deployment.
unix
{
    target.path = /usr/lib
}

!isEmpty(target.path): INSTALLS += target
