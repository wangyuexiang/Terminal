QT += widgets

SOURCES   = adddialog.cpp \
            terminalwidget.cpp \
            main.cpp \
            mainwindow.cpp \
            terminalinfotab.cpp \
            tablemodel.cpp  \
            productmodel.cpp
HEADERS   = adddialog.h \
            terminalwidget.h \
            mainwindow.h \
            terminalinfotab.h \
            tablemodel.h \
            productmodel.h\
            product.h

# install
target.path = /usr/local/lib
INSTALLS += target
