#ifndef DETECT_TASK_H
#define DETECT_TASK_H

#include <atomic>

#include <QObject>
#include <QRect>

#include "config.hpp"
#include "detection_data.hpp"
#include "image_package.hpp"
#include "pingpang_buffer.hpp"
#include "quface_common.hpp"

namespace suanzi {

class DetectTask : QObject {
  Q_OBJECT
 public:
  static DetectTask *get_instance();

  SZ_RETCODE adjust_isp_by_detection(const DetectionData *output);

 private slots:
  void rx_frame(PingPangBuffer<ImagePackage> *buffer);

 signals:
  void tx_finish();

  // for display
  void tx_bgr_display(DetectionRatio detection, bool to_clear, bool valid,
                      bool show_pose);
  void tx_nir_display(DetectionRatio detection, bool to_clear, bool valid,
                      bool show_pose);
  // for audio warning
  void tx_warn_distance();

  void tx_display_rectangle();

  // for recognition
  void tx_frame(PingPangBuffer<DetectionData> *buffer);

 private:
  DetectTask(QThread *thread = nullptr, QObject *parent = nullptr);
  ~DetectTask();

  bool detect_and_select(const MmzImage *image, DetectionRatio &detection,
                         bool is_bgr);
  bool check(DetectionRatio detection, bool is_bgr);
  bool is_stable(DetectionRatio detection);

  FaceDetectorPtr face_detector_;
  FacePoseEstimatorPtr pose_estimator_;

  std::atomic_bool buffer_inited_;
  DetectionData *buffer_ping_, *buffer_pang_;
  PingPangBuffer<DetectionData> *pingpang_buffer_;

  uint detect_count_ = 0;
  uint no_detect_count_ = 0;
};

}  // namespace suanzi

#endif
