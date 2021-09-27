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
///   Date: 9/27/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_SONY_CLIENT_MAIN_HPP
#define XOS_APP_CONSOLE_SONY_CLIENT_MAIN_HPP

#include "xos/app/console/sony/client/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace sony {
namespace client {

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
    maint(): before_write_request_(0) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy): before_write_request_(0) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    typedef typename extends::json_number_t json_number_t;
    typedef typename extends::json_node_t json_node_t;
    typedef typename extends::json_array_t json_array_t;
    typedef typename extends::json_object_t json_object_t;

    typedef typename extends::content_type_t content_type_t;
    typedef typename extends::content_type_type_which_t content_type_type_which_t;
    typedef typename extends::content_type_header_t content_type_header_t;
    typedef typename extends::content_length_header_t content_length_header_t;
    typedef typename extends::content_t content_t;

    typedef typename extends::request_t request_t;
    typedef typename extends::response_t response_t;

    enum { content_type_type_text = extends::content_type_type_text };
    typedef typename extends::content_type_subtype_which_t content_type_subtype_which_t;
    enum { content_type_subtype_json = extends::content_type_subtype_json };

    int (derives::*before_write_request_)(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env);
    virtual int before_write_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        if ((before_write_request_)) {
            err = (this->*before_write_request_)(amount, writer, request, argc, argv, env);
        } else {
            err = extends::before_write_request(amount, writer, request, argc, argv, env);
        }
        return err;
    }
    virtual int before_write_previous_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        this->set_previous();
        request.set_method(this->request_method_post());
        request.set_path(this->previous_path_);
        request.set_content_type(this->content_type_json());
        request.set_content_length(this->previous_.length());
        request.set_content(this->previous_);
        return err;
    }
    virtual int before_write_next_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        this->set_next();
        request.set_method(this->request_method_post());
        request.set_path(this->next_path_);
        request.set_content_type(this->content_type_json());
        request.set_content_length(this->next_.length());
        request.set_content(this->next_);
        return err;
    }
    virtual int before_write_pause_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        this->set_pause();
        request.set_method(this->request_method_post());
        request.set_path(this->pause_path_);
        request.set_content_type(this->content_type_json());
        request.set_content_length(this->pause_.length());
        request.set_content(this->pause_);
        return err;
    }
    virtual int before_write_stop_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        this->set_stop();
        request.set_method(this->request_method_post());
        request.set_path(this->stop_path_);
        request.set_content_type(this->content_type_json());
        request.set_content_length(this->stop_.length());
        request.set_content(this->stop_);
        return err;
    }
    virtual int before_write_resume_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        this->set_resume();
        request.set_method(this->request_method_post());
        request.set_path(this->resume_path_);
        request.set_content_type(this->content_type_json());
        request.set_content_length(this->resume_.length());
        request.set_content(this->resume_);
        return err;
    }
    virtual int before_write_replay_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        this->set_replay();
        request.set_method(this->request_method_post());
        request.set_path(this->replay_path_);
        request.set_content_type(this->content_type_json());
        request.set_content_length(this->replay_.length());
        request.set_content(this->replay_);
        return err;
    }
    virtual int before_write_get_replay_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        this->get_replay();
        request.set_method(this->request_method_post());
        request.set_path(this->replay_path_);
        request.set_content_type(this->content_type_json());
        request.set_content_length(this->replay_.length());
        request.set_content(this->replay_);
        return err;
    }
    virtual int before_write_shuffle_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        this->set_shuffle();
        request.set_method(this->request_method_post());
        request.set_path(this->shuffle_path_);
        request.set_content_type(this->content_type_json());
        request.set_content_length(this->shuffle_.length());
        request.set_content(this->shuffle_);
        return err;
    }
    virtual int before_write_get_shuffle_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        this->get_shuffle();
        request.set_method(this->request_method_post());
        request.set_path(this->shuffle_path_);
        request.set_content_type(this->content_type_json());
        request.set_content_length(this->shuffle_.length());
        request.set_content(this->shuffle_);
        return err;
    }
    virtual int before_write_volume_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        this->set_volume();
        err = write_volume_request(amount, writer, request, argc, argv, env);
        return err;
    }
    virtual int before_write_get_volume_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        this->get_volume();
        err = write_volume_request(amount, writer, request, argc, argv, env);
        return err;
    }
    virtual int write_volume_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        request.set_method(this->request_method_post());
        request.set_path(this->volume_path_);
        request.set_content_type(this->content_type_json());
        request.set_content_length(this->volume_.length());
        request.set_content(this->volume_);
        return err;
    }
    virtual int before_write_input_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        this->set_input();
        err = write_input_request(amount, writer, request, argc, argv, env);
        return err;
    }
    virtual int before_write_get_input_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        this->get_input();
        err = write_input_request(amount, writer, request, argc, argv, env);
        return err;
    }
    virtual int write_input_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        request.set_method(this->request_method_post());
        request.set_path(this->input_path_);
        request.set_content_type(this->content_type_json());
        request.set_content_length(this->input_.length());
        request.set_content(this->input_);
        return err;
    }
    virtual int before_write_power_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        this->set_power();
        err = write_power_request(amount, writer, request, argc, argv, env);
        return err;
    }
    virtual int before_write_get_power_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        this->get_power();
        err = write_power_request(amount, writer, request, argc, argv, env);
        return err;
    }
    virtual int write_power_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        request.set_method(this->request_method_post());
        request.set_path(this->power_path_);
        request.set_content_type(this->content_type_json());
        request.set_content_length(this->power_.length());
        request.set_content(this->power_);
        return err;
    }
    virtual int before_set_request_run(int argc, char_t** argv, char** env) {
        int err = 0;
        const char_t* arg = 0;
        if ((optind < argc) && (arg = argv[optind]) && (arg[0])) {
            this->set_power_status(arg);
        }
        before_write_request_ = &derives::before_write_previous_request;
        return err;
    }

    /// on...option...
    virtual int on_previous_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_connect_run(argc, argv, env))) {
            before_write_request_ = &derives::before_write_previous_request;
        }
        return err;
    }
    virtual int on_next_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_connect_run(argc, argv, env))) {
            before_write_request_ = &derives::before_write_next_request;
        }
        return err;
    }
    virtual int on_stop_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_connect_run(argc, argv, env))) {
            before_write_request_ = &derives::before_write_stop_request;
        }
        return err;
    }
    virtual int on_pause_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_connect_run(argc, argv, env))) {
            before_write_request_ = &derives::before_write_pause_request;
        }
        return err;
    }
    virtual int on_resume_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_connect_run(argc, argv, env))) {
            before_write_request_ = &derives::before_write_resume_request;
        }
        return err;
    }

    /// on...option...
    virtual int on_replay_all_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_connect_run(argc, argv, env))) {
            if ((optarg) && (optarg[0])) {
                this->set_replay(optarg);
            } else {
                this->set_replay_all();
            }
            before_write_request_ = &derives::before_write_replay_request;
        }
        return err;
    }
    virtual int on_replay_off_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_connect_run(argc, argv, env))) {
            if ((optarg) && (optarg[0])) {
                this->set_replay(optarg);
            } else {
                this->set_replay_off();
            }
            before_write_request_ = &derives::before_write_replay_request;
        }
        return err;
    }
    virtual int on_replay_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_connect_run(argc, argv, env))) {
            if ((optarg) && (optarg[0])) {
                this->set_replay(optarg);
                before_write_request_ = &derives::before_write_replay_request;
            } else {
                before_write_request_ = &derives::before_write_get_replay_request;
            }
        }
        return err;
    }
    virtual int on_shuffle_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_connect_run(argc, argv, env))) {
            if ((optarg) && (optarg[0])) {
                this->set_shuffle(optarg);
                before_write_request_ = &derives::before_write_shuffle_request;
            } else {
                before_write_request_ = &derives::before_write_get_shuffle_request;
            }
        }
        return err;
    }

    /// on...option...
    virtual int on_set_tv_input_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_connect_run(argc, argv, env))) {
            this->set_tv_input_params();
            before_write_request_ = &derives::before_write_input_request;
        } else {
        }
        return err;
    }
    virtual int on_set_hdmi_input_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        const char_t* arg = 0;
        if ((arg = optarg) && (arg[0])) {
            if (!(err = this->set_connect_run(argc, argv, env))) {
                this->set_hdmi_input_params(string_t(arg));
                before_write_request_ = &derives::before_write_input_request;
            } else {
            }
        } else {
            err = on_set_tv_input_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual int on_set_input_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        const char_t* arg = 0;
        if ((arg = optarg) && (arg[0])) {
            if (!(err = this->set_connect_run(argc, argv, env))) {
                this->set_input_params(string_t(arg));
                before_write_request_ = &derives::before_write_input_request;
            } else {
            }
        } else {
            if (!(err = this->set_connect_run(argc, argv, env))) {
                before_write_request_ = &derives::before_write_get_input_request;
            } else {
            }
        }
        return err;
    }
    virtual int on_get_input_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_connect_run(argc, argv, env))) {
            before_write_request_ = &derives::before_write_get_input_request;
        } else {
        }
        return err;
    }

    /// on...option...
    virtual int on_volume_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_connect_run(argc, argv, env))) {
            const char_t* arg = 0;
            if ((arg = optarg) && (arg[0])) {
                this->set_volume_level(string_t(arg).to_unsigned());
                before_write_request_ = &derives::before_write_volume_request;
            } else {
                before_write_request_ = &derives::before_write_get_volume_request;
            }
        }
        return err;
    }
    
    /// on...option...
    virtual int on_power_on_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_connect_run(argc, argv, env))) {
            this->set_power_status_on();
            before_write_request_ = &derives::before_write_power_request;
        }
        return err;
    }
    virtual int on_power_off_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_connect_run(argc, argv, env))) {
            this->set_power_status_off();
            before_write_request_ = &derives::before_write_power_request;
        }
        return err;
    }
    virtual int on_power_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_connect_run(argc, argv, env))) {
            const char_t* arg = 0;
            if ((arg = optarg) && (arg[0])) {
                this->set_power_status(arg);
                before_write_request_ = &derives::before_write_power_request;
            } else {
                before_write_request_ = &derives::before_write_get_power_request;
            }
        }
        return err;
    }

protected:
}; /// class maint
typedef maint<> main;

} /// namespace client
} /// namespace sony
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_SONY_CLIENT_MAIN_HPP
