########################################################################
# Copyright (c) 1988-2021 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: sonyb.pro
#
# Author: $author$
#   Date: 9/27/2021
#
# QtCreator .pro file for stara executable sonyb
########################################################################
include(../../../../../build/QtCreator/stara.pri)
include(../../../../QtCreator/stara.pri)
include(../../stara.pri)
include(../../../../QtCreator/app/sonyb/sonyb.pri)

TARGET = $${sonyb_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${sonyb_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${sonyb_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${sonyb_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${sonyb_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${sonyb_HEADERS} \
$${sonyb_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${sonyb_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${sonyb_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${sonyb_LIBS} \
$${FRAMEWORKS} \


