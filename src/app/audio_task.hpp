#ifndef AUDIO_TASK_HPP
#define AUDIO_TASK_HPP

#include <mutex>
#include <vector>

#include <QObject>
#include <QThread>

#include "person_service.hpp"

namespace suanzi {

struct Audio {
  std::vector<SZ_BYTE> data;
  int duration;
};

class AudioTask : QObject {
  Q_OBJECT
 public:
  static AudioTask* get_instance();
  static bool idle();

  void load_audio();
  void beep();

 private slots:
  void rx_report_person(PersonData person);
  void rx_report_temperature(PersonData person);

  void rx_warn_distance();

 private:
  AudioTask(QThread* thread = nullptr, QObject* parent = nullptr);
  ~AudioTask();

  bool read_audio(const std::string& name, Audio& audio);
  void play_audio(Audio& audio);

  void play_pass(PersonData person);

  Audio pass_audio_;

  Audio success_audio_;
  Audio fail_audio_;
  Audio temperature_normal_audio_;
  Audio temperature_abnormal_audio_;
  Audio warn_distance_audio_;
  Audio warn_mask_audio_;

  Audio beep_audio_;

  bool is_running_;
};

}  // namespace suanzi

#endif
