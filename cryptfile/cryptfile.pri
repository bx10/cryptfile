INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

SOURCES += \
	$$PWD/mainwindow.cpp \
	$$PWD/draganddropwidget.cpp \
	$$PWD/workingwithfiles/datafromfile.cpp \
	$$PWD/workingwithfiles/datatofile.cpp \
	$$PWD/compression/compressdata.cpp \
	$$PWD/encryptfiles.cpp \
	$$PWD/compression/compressdataworker.cpp \
	$$PWD/compression/uncompressdata.cpp \
	$$PWD/compression/uncompressdataworker.cpp \
	$$PWD/cryptography/passwordgeneration.cpp \
	$$PWD/cryptography/encryptwrapper.cpp \
	$$PWD/cryptography/decryptwrapper.cpp \
	$$PWD/workingwithfiles/checksum.cpp \
	$$PWD/workingwithfiles/settingsmanager.cpp \
	$$PWD/decryptfiles.cpp

HEADERS  += \
	$$PWD/mainwindow.h \
	$$PWD/draganddropwidget.h \
	$$PWD/workingwithfiles/datafromfile.h \
	$$PWD/workingwithfiles/datatofile.h \
	$$PWD/workingwithfiles/abstrsavedatatofile.h \
	$$PWD/workingwithfiles/abstrreaddatafromfile.h \
	$$PWD/compression/compressdata.h \
	$$PWD/encryptfiles.h \
	$$PWD/abstrclassworkwithdata.h \
	$$PWD/compression/compressdataworker.h \
	$$PWD/compression/uncompressdata.h \
	$$PWD/compression/uncompressdataworker.h \
	$$PWD/cryptography/passwordgeneration.h \
	$$PWD/cryptography/encryptwrapper.h \
	$$PWD/cryptography/decryptwrapper.h \
	$$PWD/workingwithfiles/checksum.h \
	$$PWD/workingwithfiles/settingsmanager.h \
	$$PWD/decryptfiles.h

FORMS    += \
	$$PWD/mainwindow.ui
