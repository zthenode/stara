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
#ifndef XOS_APP_CONSOLE_SONY_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_SONY_BASE_MAIN_HPP

#include "xos/app/console/sony/base/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace sony {
namespace base {

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
    maint()
    : port_(10000),
      
      system_path_("/sony/system"), 
      audio_path_("/sony/audio"), 
      avContent_path_("/sony/avContent"),
      
      previous_path_(avContent_path_),
      previous_begin_("{\"method\": \"setPlayPreviousContent\", \"id\": 73, \"params\": [{\"output\": \""),
      previous_end_("\"}], \"version\": \"1.0\"}"),
      previous_params_(""),

      next_path_(avContent_path_),
      next_begin_("{\"method\": \"setPlayNextContent\", \"id\": 73, \"params\": [{\"output\": \""),
      next_end_("\"}], \"version\": \"1.0\"}"),
      next_params_(""),

      stop_path_(avContent_path_),
      stop_begin_("{\"method\": \"stopPlayingContent\", \"id\": 73, \"params\": [{\"output\": \""),
      stop_end_("\"}], \"version\": \"1.1\"}"),
      stop_params_(""),

      pause_path_(avContent_path_),
      pause_begin_("{\"method\": \"pausePlayingContent\", \"id\": 73, \"params\": [{\"output\": \""),
      pause_end_("\"}], \"version\": \"1.1\"}"),
      pause_params_(""),

      resume_path_(avContent_path_),
      resume_begin_("{\"method\": \"setPlayContent\", \"id\": 73, \"params\": [{\"output\": \"\", \"resume\": "),
      resume_end_("}], \"version\": \"1.2\"}"),
      resume_params_("true"),

      replay_path_(avContent_path_),
      get_replay_begin_("{\"method\": \"getPlayingContentInfo\", \"id\": 73, \"params\": [{\"output\": \""),
      get_replay_end_("\"}], \"version\": \"1.2\"}"),
      replay_begin_("{\"method\": \"setPlaybackModeSettings\", \"id\": 73, \"params\": [{\"settings\": [{\"target\": \"repeatType\", \"value\": \""),
      replay_end_("\"}]}], \"version\": \"1.0\"}"),
      replay_all_("all"), replay_off_("off"), replay_params_(replay_all_),
      
      shuffle_path_(avContent_path_),
      get_shuffle_begin_("{\"method\": \"getPlaybackModeSettings\", \"id\": 73, \"params\": [{\"target\": \"shuffleType\", \"uri\": \""),
      get_shuffle_end_("extInput:bd-dvd\"}], \"version\": \"1.0\"}"),
      shuffle_begin_("{\"method\": \"setPlaybackModeSettings\", \"id\": 73, \"params\": [{\"settings\": [{\"target\": \"shuffleType\", \"value\": \""),
      shuffle_end_("\"}]}], \"version\": \"1.0\"}"),
      shuffle_all_("all"), shuffle_off_("off"), shuffle_params_(shuffle_all_),

      volume_level_(10), volume_value_(volume_level_), volume_param_("volume", volume_value_), 
      volume_object_(&volume_param_, null), volume_params_(&volume_object_, null),
      volume_path_(audio_path_),
      get_volume_begin_("{\"method\": \"getVolumeInformation\", \"id\": 73, \"params\": [{\"output\": \"\"}]"),
      volume_begin_("{\"method\": \"setAudioVolume\", \"id\": 73, \"params\": "),
      volume_end_(", \"version\": \"1.1\"}"),
      
      hdmi_input_param_("extInput:hdmi?port="), tv_input_param_("extInput:tv"), 
      input_path_(avContent_path_),
      get_input_begin_("{\"method\": \"getPlayingContentInfo\", \"id\": 73, \"params\": [{\"output\": \""),
      input_begin_("{\"method\": \"setPlayContent\", \"id\": 73, \"params\": [{\"output\": \"\", \"resume\": true, \"uri\": \""),
      input_end_("\"}], \"version\": \"1.2\"}"),
      
      power_status_on_("active"), power_status_off_("off"), 
      power_status_(power_status_on_), power_value_(power_status_), power_param_("status", power_value_), 
      power_object_(&power_param_, null), power_params_(&power_object_, null),
      power_path_(system_path_),
      get_power_begin_("{\"method\": \"getPowerStatus\", \"id\": 73, \"params\": []"),
      power_begin_("{\"method\": \"setPowerStatus\", \"id\": 73, \"params\": "),
      power_end_(", \"version\": \"1.1\"}") {
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
    
    typedef typename extends::json_number_t json_number_t;
    typedef typename extends::json_node_t json_node_t;
    typedef typename extends::json_array_t json_array_t;
    typedef typename extends::json_object_t json_object_t;

    typedef typename extends::content_type_t content_type_t;
    typedef typename extends::content_type_type_which_t content_type_type_which_t;
    typedef typename extends::content_type_header_t content_type_header_t;
    typedef typename extends::content_length_header_t content_length_header_t;
    typedef typename extends::content_t content_t;

    /// ...power...
    virtual string_t& set_power_status_on() {
        return set_power_status(power_status_on_.chars());
    }
    virtual string_t& set_power_status_off() {
        return set_power_status(power_status_off_.chars());
    }
    virtual string_t& set_power_status(const char_t* to) {
        power_status_.assign(to);
        power_value_.set(power_status_);
        power_param_.set(power_value_);
        power_object_.set(&power_param_, null);
        power_params_.set(&power_object_, null);
        return power_;
    }
    virtual string_t& set_power() {
        power_.assign(power_begin_);
        power_.append(power_params_);
        power_.append(power_end_);
        return power_;
    }
    virtual string_t& get_power() {
        power_.assign(get_power_begin_);
        power_.append(power_end_);
        return power_;
    }

    /// ...input...
    virtual string_t& set_tv_input_params() {
        input_params_.assign(tv_input_param_);
        return input_params_;
    }
    virtual string_t& set_hdmi_input_params(const string_t& to) {
        input_params_.assign(hdmi_input_param_);
        input_params_.append(to);
        return input_params_;
    }
    virtual string_t& set_input_params(const string_t& to) {
        input_params_.assign(to);
        return input_params_;
    }
    virtual string_t& set_input() {
        input_.assign(input_begin_);
        input_.append(input_params_);
        input_.append(input_end_);
        return input_;
    }
    virtual string_t& get_input() {
        input_.assign(get_input_begin_);
        input_.append(input_end_);
        return input_;
    }

    /// ...volume...
    virtual string_t& set_volume_level(unsigned to) {
        volume_level_ = to;
        volume_value_.set(unsigned_to_string(volume_level_));
        volume_param_.set(volume_value_);
        volume_object_.set(&volume_param_, null);
        volume_params_.set(&volume_object_, null);
        return volume_;
    }
    virtual string_t& set_volume() {
        volume_.assign(volume_begin_);
        volume_.append(volume_params_);
        volume_.append(volume_end_);
        return volume_;
    }
    virtual string_t& get_volume() {
        volume_.assign(get_volume_begin_);
        volume_.append(volume_end_);
        return volume_;
    }

    /// ...shuffle...
    virtual string_t& set_shuffle(const string_t& to) {
        set_shuffle(to.chars());
        return shuffle_;
    }
    virtual string_t& set_shuffle(const char_t* to) {
        if ((to) && (to[0])) {
            shuffle_params_.assign(to);
        }
        return shuffle_;
    }
    virtual string_t& set_shuffle_all() {
        set_shuffle(shuffle_all_);
        return shuffle_;
    }
    virtual string_t& set_shuffle_off() {
        set_shuffle(shuffle_off_);
        return shuffle_;
    }
    virtual string_t& set_shuffle() {
        shuffle_.assign(shuffle_begin_);
        shuffle_.append(shuffle_params_);
        shuffle_.append(shuffle_end_);
        return shuffle_;
    }
    virtual string_t& get_shuffle() {
        shuffle_.assign(get_shuffle_begin_);
        shuffle_.append(get_shuffle_end_);
        return shuffle_;
    }

    /// ...replay...
    virtual string_t& set_replay(const string_t& to) {
        set_replay(to.chars());
        return replay_;
    }
    virtual string_t& set_replay(const char_t* to) {
        if ((to) && (to[0])) {
            replay_params_.assign(to);
        }
        return replay_;
    }
    virtual string_t& set_replay_all() {
        set_replay(replay_all_);
        return replay_;
    }
    virtual string_t& set_replay_off() {
        set_replay(replay_off_);
        return replay_;
    }
    virtual string_t& set_replay() {
        replay_.assign(replay_begin_);
        replay_.append(replay_params_);
        replay_.append(replay_end_);
        return replay_;
    }
    virtual string_t& get_replay() {
        replay_.assign(get_replay_begin_);
        replay_.append(get_replay_end_);
        return replay_;
    }

    /// ...next...
    virtual string_t& set_previous() {
        previous_.assign(previous_begin_);
        previous_.append(previous_params_);
        previous_.append(previous_end_);
        return previous_;
    }
    virtual string_t& set_next() {
        next_.assign(next_begin_);
        next_.append(next_params_);
        next_.append(next_end_);
        return next_;
    }
    virtual string_t& set_stop() {
        stop_.assign(stop_begin_);
        stop_.append(stop_params_);
        stop_.append(stop_end_);
        return stop_;
    }
    virtual string_t& set_pause() {
        pause_.assign(pause_begin_);
        pause_.append(pause_params_);
        pause_.append(pause_end_);
        return pause_;
    }
    virtual string_t& set_resume() {
        resume_.assign(resume_begin_);
        resume_.append(resume_params_);
        resume_.append(resume_end_);
        return resume_;
    }

    /// ...port
    virtual short& accept_port() const {
        return port();
    }
    virtual short& connect_port() const {
        return port();
    }
    virtual short& set_port(short to) {
        port_ = to;
        return port();
    }
    virtual short& port() const {
        return (short&)port_;
    }

protected:
    short port_;

    string_t system_path_, audio_path_, avContent_path_;

    string_t previous_path_, previous_begin_, previous_end_, previous_params_, previous_;
    string_t next_path_, next_begin_, next_end_, next_params_, next_;
    string_t stop_path_, stop_begin_, stop_end_, stop_params_, stop_;
    string_t pause_path_, pause_begin_, pause_end_, pause_params_, pause_;
    string_t resume_path_, resume_begin_, resume_end_, resume_params_, resume_;

    string_t replay_path_, get_replay_begin_, get_replay_end_, replay_begin_, replay_end_, replay_all_, replay_off_, replay_params_, replay_;
    string_t shuffle_path_, get_shuffle_begin_, get_shuffle_end_, shuffle_begin_, shuffle_end_, shuffle_all_, shuffle_off_, shuffle_params_, shuffle_;

    unsigned volume_level_; json_node_t volume_value_, volume_param_;
    json_object_t volume_object_; json_array_t volume_params_;
    string_t volume_path_, get_volume_begin_, volume_begin_, volume_end_, volume_;
    
    string_t hdmi_input_param_, tv_input_param_, input_params_, 
             input_path_, get_input_begin_, input_begin_, input_end_, input_;
    
    string_t power_status_on_, power_status_off_, power_status_; json_node_t power_value_, power_param_;
    json_object_t power_object_; json_array_t power_params_;
    string_t power_path_, get_power_begin_, power_begin_, power_end_, power_;
}; /// class maint
typedef maint<> main;

} /// namespace base
} /// namespace sony
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_SONY_BASE_MAIN_HPP
