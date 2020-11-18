#include "status_banner.hpp"

#include <QDateTime>
#include <QFontDatabase>
#include <QPainter>
#include <QStringList>

#include "config.hpp"
#include "system.hpp"

using namespace suanzi;

StatusBanner::StatusBanner(int width, int height, QWidget *parent)
    : QWidget(parent),
      icon1_(":asserts/people.png"),
      icon2_(":asserts/temperature.png"),
      icon3_(":asserts/wired_network.png"),
      icon4_(":asserts/face.png"),
      icon5_(":asserts/file.png"),
      icon6_(":asserts/wireless_network.png"),
      icon7_(":asserts/no_network.png") {
  person_service_ = PersonService::get_instance();
  db_ = std::make_shared<FaceDatabase>(Config::get_quface().db_name);
  db_->size(db_size_);

  QPalette palette = this->palette();
  palette.setColor(QPalette::Background, Qt::transparent);
  setPalette(palette);

  move(0, 0);
  setFixedSize(width, height);

  rx_update();
  timer_ = new QTimer(this);
  connect(timer_, SIGNAL(timeout()), this, SLOT(rx_update()));
  timer_->start(1000);
}

StatusBanner::~StatusBanner() { timer_->stop(); }

void StatusBanner::rx_update() {
  System::get_current_network(name_, ip_, mac_);

  if (SZ_RETCODE_OK != db_->size(db_size_)) db_size_ = 0;
}

void StatusBanner::paint(QPainter *painter) {
  const int w = width();
  const int h = height();

  auto cfg = Config::get_user();

  // draw background
  // painter->fillRect(QRect(0, 0, w, 0.02734375 * h), QColor(5, 0, 20, 150));

  // draw person count
  QFont font = painter->font();
  font.setPointSize(0.02125 * w);
  painter->setFont(font);
  painter->setPen(QPen(QColor(255, 255, 255, 200), 2));
  painter->drawText(0.04125 * w, 0.01953125 * h,
                    std::to_string(db_size_).c_str());

  painter->drawPixmap(QRect(0.01 * w, 0.0078125 * h, 0.025 * w, 0.0140625 * h),
                      icon1_, QRect());
  if (cfg.enable_temperature)
    painter->drawPixmap(
        QRect(0.875 * w, 0.00234375 * h, 0.0375 * w, 0.0234375 * h), icon2_,
        QRect());

  QPixmap network_icon = icon7_;
  if (name_ == "eth0") network_icon = icon3_;
  if (name_ == "wlan0") network_icon = icon6_;
  painter->drawPixmap(
      QRect(0.96 * w, 0.00546875 * h, 0.0275 * w, 0.0171875 * h), network_icon,
      QRect());

  painter->drawPixmap(
      QRect(0.91875 * w, 0.00546875 * h, 0.0275 * w, 0.0171875 * h), icon4_,
      QRect());
  // painter->drawPixmap(
  //     QRect(0.84 * w, 0.0046875 * h, 0.03125 * w, 0.01796875 * h), icon5_,
  //     QRect());
}
