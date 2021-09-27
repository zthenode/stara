///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2021 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: main.hpp
///
/// Author: $author$
///   Date: 9/17/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_PROTOCOL_HTTP_CGI_ENVIRONMENT_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_HTTP_CGI_ENVIRONMENT_MAIN_HPP

#include "xos/app/console/network/protocol/http/cgi/environment/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace network {
namespace protocol {
namespace http {
namespace cgi {
namespace environment {

/// class maint
template 
<class TExtends = main_opt, 
 class TImplements = typename TExtends::implements>

class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    maint() {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    /// ...gateway_console_run
    virtual int gateway_console_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->all_gateway_run(argc, argv, env);
        return err;
    }

    /// ...gateway_run
    virtual int before_gateway_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        this->set_gateway_in_std_in();
        this->set_gateway_out_std_out();
        return err;
    }
    virtual int after_gateway_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        this->unset_in_std_in();
        this->unset_out_std_out();
        return err;
    }

    /// ...console_gateway_out_run
    virtual int console_gateway_out_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        this->outln("environment:\n");
        if ((env)) {
            for (const char_t* e = *(env); e; e = *(++env)) {
                this->outln(e);
            }
        }
        return err;
    }

protected:
}; /// class maint
typedef maint<> main;

} /// namespace environment
} /// namespace cgi
} /// namespace http
} /// namespace protocol
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_NETWORK_PROTOCOL_HTTP_CGI_ENVIRONMENT_MAIN_HPP
