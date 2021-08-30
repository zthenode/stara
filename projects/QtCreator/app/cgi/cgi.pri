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
#   File: cgi.pri
#
# Author: $author$
#   Date: 8/20/2021
#
# QtCreator .pri file for stara executable cgi
########################################################################

########################################################################
# cgi

# cgi TARGET
#
cgi_TARGET = cgi

# cgi INCLUDEPATH
#
cgi_INCLUDEPATH += \
$${stara_INCLUDEPATH} \

# cgi DEFINES
#
cgi_DEFINES += \
$${stara_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_APP_CONSOLE_NETWORK_PROTOCOL_HTTP_CGI_MAIN_INSTANCE \

########################################################################
# cgi OBJECTIVE_HEADERS
#
#cgi_OBJECTIVE_HEADERS += \
#$${STARA_SRC}/xos/app/console/network/protocol/http/cgi/main.hh \

# cgi OBJECTIVE_SOURCES
#
#cgi_OBJECTIVE_SOURCES += \
#$${STARA_SRC}/xos/app/console/network/protocol/http/cgi/main.mm \

########################################################################
# cgi HEADERS
#
cgi_HEADERS += \
$${NADIR_SRC}/xos/base/string.hpp \
$${NADIR_SRC}/xos/base/chars.hpp \
$${NADIR_SRC}/xos/io/seeker.hpp \
$${NADIR_SRC}/xos/io/reader.hpp \
$${NADIR_SRC}/xos/io/writer.hpp \
$${NADIR_SRC}/xos/io/string/reader.hpp \
$${NADIR_SRC}/xos/io/crt/file/attached.hpp \
\
$${STARA_SRC}/xos/protocol/http/url/encoded/reader.hpp \
$${STARA_SRC}/xos/protocol/http/url/encoded/form/content/type.hpp \
\
$${STARA_SRC}/xos/protocol/http/form/content.hpp \
$${STARA_SRC}/xos/protocol/http/form/field.hpp \
$${STARA_SRC}/xos/protocol/http/form/fields.hpp \
\
$${STARA_SRC}/xos/protocol/http/cgi/identifier.hpp \
$${STARA_SRC}/xos/protocol/http/cgi/environment/variable/name.hpp \
$${STARA_SRC}/xos/protocol/http/cgi/environment/variable/value.hpp \
$${STARA_SRC}/xos/protocol/http/cgi/environment/variable/setting.hpp \
$${STARA_SRC}/xos/protocol/http/cgi/environment/variable/values.hpp \
\
$${STARA_SRC}/xos/app/console/network/protocol/http/cgi/main_opt.hpp \
$${STARA_SRC}/xos/app/console/network/protocol/http/cgi/main.hpp \
\
$${NADIR_SRC}/xos/console/main_main.hpp \

# cgi SOURCES
#
cgi_SOURCES += \
$${STARA_SRC}/xos/app/console/network/protocol/http/cgi/main_opt.cpp \
$${STARA_SRC}/xos/app/console/network/protocol/http/cgi/main.cpp \
\
$${NADIR_SRC}/xos/console/main_main.cpp \

########################################################################
# cgi FRAMEWORKS
#
cgi_FRAMEWORKS += \
$${stara_FRAMEWORKS} \

# cgi LIBS
#
cgi_LIBS += \
$${stara_LIBS} \


