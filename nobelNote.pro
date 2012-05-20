TEMPLATE = app
TARGET = bin/nobleNote
DEPENDPATH = . src
INCLUDEPATH = . src
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
RCC_DIR = build

# Input
HEADERS = src/mainwindow.h src/note.h \
    src/filesystemmodel.h \
    src/preferences.h \
    src/findfilesystemmodel.h \
    src/findfilemodel.h \
    src/lineedit.h \
    src/xorcipher.h \
    src/xmlnote.h \
    src/textformattingtoolbar.h \
    src/newnotename.h

FORMS = src/ui/note.ui src/ui/mainwindow.ui src/ui/preferences.ui \
        src/ui/newnotename.ui
SOURCES = src/main.cpp src/mainwindow.cpp src/note.cpp \
    src/preferences.cpp \
    src/findfilemodel.cpp \
    src/findfilesystemmodel.cpp src/lineedit.cpp \
    src/xorcipher.cpp \
    src/xmlnote.cpp \
    src/textformattingtoolbar.cpp \
    src/newnotename.cpp
RESOURCES = nobleNote.qrc
