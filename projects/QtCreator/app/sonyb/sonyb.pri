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
#   File: sonyb.pri
#
# Author: $author$
#   Date: 9/27/2021
#
# QtCreator .pri file for stara executable sonyb
########################################################################

########################################################################
# sonyb

# sonyb TARGET
#
sonyb_TARGET = sonyb

# sonyb INCLUDEPATH
#
sonyb_INCLUDEPATH += \
$${stara_INCLUDEPATH} \

# sonyb DEFINES
#
sonyb_DEFINES += \
$${stara_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_APP_CONSOLE_SONY_BASE_MAIN_INSTANCE \

########################################################################
# sonyb OBJECTIVE_HEADERS
#
#sonyb_OBJECTIVE_HEADERS += \
#$${STARA_SRC}/xos/app/console/sony/base/main.hh \

# sonyb OBJECTIVE_SOURCES
#
#sonyb_OBJECTIVE_SOURCES += \
#$${STARA_SRC}/xos/app/console/sony/base/main.mm \

########################################################################
# sonyb HEADERS
#
sonyb_HEADERS += \
$${NADIR_SRC}/xos/base/string.hpp \
\
$${STARA_SRC}/xos/protocol/xttp/content/json/node_type.hpp \
$${STARA_SRC}/xos/protocol/xttp/content/json/boolean.hpp \
$${STARA_SRC}/xos/protocol/xttp/content/json/number.hpp \
$${STARA_SRC}/xos/protocol/xttp/content/json/string.hpp \
$${STARA_SRC}/xos/protocol/xttp/content/json/node.hpp \
$${STARA_SRC}/xos/protocol/xttp/content/json/array.hpp \
$${STARA_SRC}/xos/protocol/xttp/content/json/object.hpp \
\
$${RETE_SRC}/xos/app/console/network/base/main_opt.hpp \
$${RETE_SRC}/xos/app/console/network/base/main.hpp \
$${RETE_SRC}/xos/app/console/network/client/main_opt.hpp \
$${RETE_SRC}/xos/app/console/network/client/main.hpp \
$${RETE_SRC}/xos/app/console/network/server/main_opt.hpp \
$${RETE_SRC}/xos/app/console/network/server/main.hpp \
$${RETE_SRC}/xos/app/console/network/main_opt.hpp \
$${RETE_SRC}/xos/app/console/network/main.hpp \
\
$${STARA_SRC}/xos/app/console/protocol/xttp/base/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/base/main.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/client/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/client/main.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/server/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/server/main.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/xttp/main.hpp \
\
$${STARA_SRC}/xos/app/console/protocol/http/base/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/http/base/main.hpp \
$${STARA_SRC}/xos/app/console/protocol/http/client/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/http/client/main.hpp \
$${STARA_SRC}/xos/app/console/protocol/http/server/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/http/server/main.hpp \
$${STARA_SRC}/xos/app/console/protocol/http/main_opt.hpp \
$${STARA_SRC}/xos/app/console/protocol/http/main.hpp \
\
$${STARA_SRC}/xos/app/console/xttp/base/main_opt.hpp \
$${STARA_SRC}/xos/app/console/xttp/base/main.hpp \
$${STARA_SRC}/xos/app/console/xttp/client/main_opt.hpp \
$${STARA_SRC}/xos/app/console/xttp/client/main.hpp \
$${STARA_SRC}/xos/app/console/xttp/server/main_opt.hpp \
$${STARA_SRC}/xos/app/console/xttp/server/main.hpp \
$${STARA_SRC}/xos/app/console/xttp/main_opt.hpp \
$${STARA_SRC}/xos/app/console/xttp/main.hpp \
\
$${STARA_SRC}/xos/app/console/http/base/main_opt.hpp \
$${STARA_SRC}/xos/app/console/http/base/main.hpp \
$${STARA_SRC}/xos/app/console/http/client/main_opt.hpp \
$${STARA_SRC}/xos/app/console/http/client/main.hpp \
$${STARA_SRC}/xos/app/console/http/server/main_opt.hpp \
$${STARA_SRC}/xos/app/console/http/server/main.hpp \
$${STARA_SRC}/xos/app/console/http/main_opt.hpp \
$${STARA_SRC}/xos/app/console/http/main.hpp \
\
$${STARA_SRC}/xos/app/console/sony/base/main_opt.hpp \
$${STARA_SRC}/xos/app/console/sony/base/main.hpp \
$${STARA_SRC}/xos/app/console/sony/client/main_opt.hpp \
$${STARA_SRC}/xos/app/console/sony/client/main.hpp \
$${STARA_SRC}/xos/app/console/sony/server/main_opt.hpp \
$${STARA_SRC}/xos/app/console/sony/server/main.hpp \
$${STARA_SRC}/xos/app/console/sony/main_opt.hpp \
$${STARA_SRC}/xos/app/console/sony/main.hpp \
\
$${NADIR_SRC}/xos/console/main_main.hpp \

# sonyb SOURCES
#
sonyb_SOURCES += \
$${NADIR_SRC}/xos/base/string.cpp \
\
$${STARA_SRC}/xos/protocol/xttp/content/json/node_type.cpp \
$${STARA_SRC}/xos/protocol/xttp/content/json/boolean.cpp \
$${STARA_SRC}/xos/protocol/xttp/content/json/number.cpp \
$${STARA_SRC}/xos/protocol/xttp/content/json/string.cpp \
$${STARA_SRC}/xos/protocol/xttp/content/json/node.cpp \
$${STARA_SRC}/xos/protocol/xttp/content/json/array.cpp \
$${STARA_SRC}/xos/protocol/xttp/content/json/object.cpp \
\
$${STARA_SRC}/xos/app/console/sony/base/main_opt.cpp \
$${STARA_SRC}/xos/app/console/sony/base/main.cpp \
\
$${NADIR_SRC}/xos/console/main_main.cpp \

########################################################################
# sonyb FRAMEWORKS
#
sonyb_FRAMEWORKS += \
$${stara_FRAMEWORKS} \

# sonyb LIBS
#
sonyb_LIBS += \
$${stara_LIBS} \

########################################################################
# NO Qt
QT -= gui core


