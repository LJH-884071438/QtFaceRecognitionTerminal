#ifndef DETECTTIPWIDGET_H
#define DETECTTIPWIDGET_H

#include <QImage>
#include <QPainter>
#include <QVBoxLayout>
#include <QWidget>

#include "detection_data.hpp"
#include "image_package.hpp"
#include "pingpang_buffer.hpp"

namespace suanzi {

class DetectTipWidget : public QWidget {
  Q_OBJECT

 public:
  DetectTipWidget(int win_x, int win_y, int win_width, int win_height,
                  QWidget *parent = nullptr);
  ~DetectTipWidget() override;

  void paint(QPainter *painter);

  void timerEvent(QTimerEvent *event) override;

  void paintEvent(QPaintEvent *event) override;

 private slots:
  void rx_display(DetectionRatio detection, bool to_clear, bool valid,
                  bool is_bgr);

 private:
  static constexpr int MAX_RECT_COUNT = 10;
  static constexpr int MAX_LOST_AGE = 5;

  std::vector<QRect> rects_;
  QPolygon landmarks_;
  QString pose_;

  int win_x_;
  int win_y_;
  int win_width_;
  int win_height_;

  int lost_age_;

  bool is_valid_;
  int valid_count_;
};

}  // namespace suanzi

#endif
