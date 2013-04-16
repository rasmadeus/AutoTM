SOURCES += \
    main.cpp \
    telemetry/Item.cpp \
    telemetry/package/Package.cpp \
    telemetry/package/Column.cpp \
    telemetry/package/9M100/TM1_9M100.cpp \
    telemetry/package/PackagesMaker.cpp \
    paths/Paths.cpp \
    telemetry/package/9M100/TM2_9M100.cpp \
    telemetry/package/9M100/TM3_9M100.cpp \
    telemetry/package/9M100/TM4_9M100.cpp \
    view/Menu.cpp \
    model/Model.cpp

HEADERS += \
    telemetry/Item.h \
    telemetry/package/Package.h \
    telemetry/package/Column.h \
    telemetry/package/9M100/TM1_9M100.h \
    telemetry/package/PackagesMaker.h \
    paths/Paths.h \
    telemetry/package/9M100/TM2_9M100.h \
    telemetry/package/9M100/TM3_9M100.h \
    telemetry/package/9M100/TM4_9M100.h \
    model/Model.h \
    view/Menu.h

OTHER_FILES += \
    view/qml/MainWindow.qml \
    view/qml/Button.qml \
    view/qml/Menu.qml

QT += declarative

RC_FILE = icon.rc




























