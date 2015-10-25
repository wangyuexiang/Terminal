QT += widgets

SOURCES   = adddialog.cpp \
            terminalwidget.cpp \
            main.cpp \
            mainwindow.cpp \
            newaddresstab.cpp \
            tablemodel.cpp  \
            productmodel.cpp
HEADERS   = adddialog.h \
            terminalwidget.h \
            mainwindow.h \
            newaddresstab.h \
            tablemodel.h \
            productmodel.h\
            product.h

# install
target.path = /usr/local/lib
INSTALLS += target
