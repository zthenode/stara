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
#   File: httpc.pro
#
# Author: $author$
#   Date: 9/26/2021
#
# QtCreator .pro file for stara executable httpc
########################################################################
include(../../../../../build/QtCreator/stara.pri)
include(../../../../QtCreator/stara.pri)
include(../../stara.pri)
include(../../../../QtCreator/app/httpc/httpc.pri)

TARGET = $${httpc_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${httpc_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${httpc_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${httpc_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${httpc_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${httpc_HEADERS} \
$${httpc_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${httpc_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${httpc_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${httpc_LIBS} \
$${FRAMEWORKS} \


