QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../calc_functions/s21_calculate.c \
    ../calc_functions/s21_parser.c \
    ../calc_functions/s21_stack.c \
    ../calc_functions/s21_start_calc.c \
    main.cpp \
    mainwindow.cpp \
    plotwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    ../calc_functions/s21_smart_calc.h \
    mainwindow.h \
    plotwindow.h \
    qcustomplot.h

FORMS += \
    mainwindow.ui \
    plotwindow.ui

QT += widgets printsupport

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
