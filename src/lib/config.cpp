#include "config.hpp"

using namespace suanzi;

#define LOAD_JSON_TO(config, key, value) \
  if (config.contains(key)) {            \
    config.at(key).get_to(value);        \
  }

#define SAVE_JSON_TO(config, key, value) config[key] = value;

void suanzi::to_json(json &j, const UserConfig &c) {
  SAVE_JSON_TO(j, "blacklist_policy", c.blacklist_policy);
  SAVE_JSON_TO(j, "detect_level", c.detect_level);
  SAVE_JSON_TO(j, "extract_level", c.extract_level);
  SAVE_JSON_TO(j, "liveness_level", c.liveness_level);
  SAVE_JSON_TO(j, "duplication_interval", c.duplication_interval);
}

void suanzi::from_json(const json &j, UserConfig &c) {
  LOAD_JSON_TO(j, "blacklist_policy", c.blacklist_policy);
  LOAD_JSON_TO(j, "detect_level", c.detect_level);
  LOAD_JSON_TO(j, "extract_level", c.extract_level);
  LOAD_JSON_TO(j, "liveness_level", c.liveness_level);
  LOAD_JSON_TO(j, "duplication_interval", c.duplication_interval);
}

void suanzi::to_json(json &j, const AppConfig &c) {
  SAVE_JSON_TO(j, "server_port", c.server_port);
  SAVE_JSON_TO(j, "server_host", c.server_host);
  SAVE_JSON_TO(j, "image_store_path", c.image_store_path);
  SAVE_JSON_TO(j, "person_service_base_url", c.person_service_base_url);
}

void suanzi::from_json(const json &j, AppConfig &c) {
  LOAD_JSON_TO(j, "server_port", c.server_port);
  LOAD_JSON_TO(j, "server_host", c.server_host);
  LOAD_JSON_TO(j, "image_store_path", c.image_store_path);
  LOAD_JSON_TO(j, "person_service_base_url", c.person_service_base_url);
}

void suanzi::to_json(json &j, const QufaceConfig &c) {
  SAVE_JSON_TO(j, "product_key", c.product_key);
  SAVE_JSON_TO(j, "device_name", c.device_name);
  SAVE_JSON_TO(j, "device_secret", c.device_secret);
  SAVE_JSON_TO(j, "client_id", c.client_id);
  SAVE_JSON_TO(j, "db_name", c.db_name);
  SAVE_JSON_TO(j, "model_file_path", c.model_file_path);
  SAVE_JSON_TO(j, "license_filename", c.license_filename);
}

void suanzi::from_json(const json &j, QufaceConfig &c) {
  LOAD_JSON_TO(j, "product_key", c.product_key);
  LOAD_JSON_TO(j, "device_name", c.device_name);
  LOAD_JSON_TO(j, "device_secret", c.device_secret);
  LOAD_JSON_TO(j, "client_id", c.client_id);
  LOAD_JSON_TO(j, "db_name", c.db_name);
  LOAD_JSON_TO(j, "model_file_path", c.model_file_path);
  LOAD_JSON_TO(j, "license_filename", c.license_filename);
}

void suanzi::to_json(json &j, const CameraConfig &c) {
  SAVE_JSON_TO(j, "index", c.index);
  SAVE_JSON_TO(j, "rotate", c.rotate);
  SAVE_JSON_TO(j, "flip", c.flip);
  SAVE_JSON_TO(j, "min_face_height", c.min_face_height);
  SAVE_JSON_TO(j, "min_face_width", c.min_face_width);
  SAVE_JSON_TO(j, "max_window_height", c.max_window_height);
  SAVE_JSON_TO(j, "max_window_width", c.max_window_width);
  SAVE_JSON_TO(j, "target_area_width_percent", c.target_area_width_percent);
  SAVE_JSON_TO(j, "target_area_height_percent", c.target_area_height_percent);
}

void suanzi::from_json(const json &j, CameraConfig &c) {
  LOAD_JSON_TO(j, "index", c.index);
  LOAD_JSON_TO(j, "rotate", c.rotate);
  LOAD_JSON_TO(j, "flip", c.flip);
  LOAD_JSON_TO(j, "min_face_height", c.min_face_height);
  LOAD_JSON_TO(j, "min_face_width", c.min_face_width);
  LOAD_JSON_TO(j, "max_window_height", c.max_window_height);
  LOAD_JSON_TO(j, "max_window_width", c.max_window_width);
  LOAD_JSON_TO(j, "target_area_width_percent", c.target_area_width_percent);
  LOAD_JSON_TO(j, "target_area_height_percent", c.target_area_height_percent);
}

void suanzi::to_json(json &j, const DetectConfig &c) {
  SAVE_JSON_TO(j, "threshold", c.threshold);
  SAVE_JSON_TO(j, "min_face_size", c.min_face_size);
  SAVE_JSON_TO(j, "max_yaw", c.max_yaw);
  SAVE_JSON_TO(j, "min_yaw", c.min_yaw);
  SAVE_JSON_TO(j, "max_pitch", c.max_pitch);
  SAVE_JSON_TO(j, "min_pitch", c.min_pitch);
}

void suanzi::from_json(const json &j, DetectConfig &c) {
  LOAD_JSON_TO(j, "threshold", c.threshold);
  LOAD_JSON_TO(j, "min_face_size", c.min_face_size);
  LOAD_JSON_TO(j, "max_yaw", c.max_yaw);
  LOAD_JSON_TO(j, "min_yaw", c.min_yaw);
  LOAD_JSON_TO(j, "max_pitch", c.max_pitch);
  LOAD_JSON_TO(j, "min_pitch", c.min_pitch);
}

void suanzi::to_json(json &j, const ExtractConfig &c) {
  SAVE_JSON_TO(j, "history_size", c.history_size);
  SAVE_JSON_TO(j, "min_recognize_count", c.min_recognize_count);
  SAVE_JSON_TO(j, "min_recognize_score", c.min_recognize_score);
  SAVE_JSON_TO(j, "min_accumulate_score", c.min_accumulate_score);
  SAVE_JSON_TO(j, "max_lost_age", c.max_lost_age);
  SAVE_JSON_TO(j, "min_interval_between_same_records",
               c.min_interval_between_same_records);
  SAVE_JSON_TO(j, "show_black_list", c.show_black_list);
}

void suanzi::from_json(const json &j, ExtractConfig &c) {
  LOAD_JSON_TO(j, "history_size", c.history_size);
  LOAD_JSON_TO(j, "min_recognize_count", c.min_recognize_count);
  LOAD_JSON_TO(j, "min_recognize_score", c.min_recognize_score);
  LOAD_JSON_TO(j, "min_accumulate_score", c.min_accumulate_score);
  LOAD_JSON_TO(j, "max_lost_age", c.max_lost_age);
  LOAD_JSON_TO(j, "min_interval_between_same_records",
               c.min_interval_between_same_records);
  LOAD_JSON_TO(j, "show_black_list", c.show_black_list);
}

void suanzi::to_json(json &j, const LivenessConfig &c) {
  SAVE_JSON_TO(j, "enable", c.enable);
  SAVE_JSON_TO(j, "history_size", c.history_size);
  SAVE_JSON_TO(j, "min_alive_count", c.min_alive_count);
  SAVE_JSON_TO(j, "continuous_max_lost_count", c.continuous_max_lost_count);
  SAVE_JSON_TO(j, "max_no_face", c.max_no_face);
}

void suanzi::from_json(const json &j, LivenessConfig &c) {
  LOAD_JSON_TO(j, "enable", c.enable);
  LOAD_JSON_TO(j, "history_size", c.history_size);
  LOAD_JSON_TO(j, "min_alive_count", c.min_alive_count);
  LOAD_JSON_TO(j, "continuous_max_lost_count", c.continuous_max_lost_count);
  LOAD_JSON_TO(j, "max_no_face", c.max_no_face);
}

void suanzi::from_json(const json &j, Config &c) {
  LOAD_JSON_TO(j, "user", c.user);
  LOAD_JSON_TO(j, "app", c.app);
  LOAD_JSON_TO(j, "quface", c.quface);

  if (j.contains("cameras")) {
    LOAD_JSON_TO(j.at("cameras"), "normal", c.normal);
    LOAD_JSON_TO(j.at("cameras"), "infrared", c.infrared);
  }

  if (j.contains("pro")) {
    LOAD_JSON_TO(j.at("pro"), "detect_levels", c.detect_levels);
    LOAD_JSON_TO(j.at("pro"), "extract_levels", c.extract_levels);
    LOAD_JSON_TO(j.at("pro"), "liveness_levels", c.extract_levels);
  }
}

void suanzi::to_json(json &j, const Config &c) {
  SAVE_JSON_TO(j, "user", c.user);
  SAVE_JSON_TO(j, "app", c.app);
  SAVE_JSON_TO(j, "quface", c.quface);

  json cameras;
  SAVE_JSON_TO(cameras, "normal", c.normal);
  SAVE_JSON_TO(cameras, "infrared", c.infrared);
  SAVE_JSON_TO(j, "cameras", cameras);

  json pro;
  SAVE_JSON_TO(pro, "detect_levels", c.detect_levels);
  SAVE_JSON_TO(pro, "extract_levels", c.extract_levels);
  SAVE_JSON_TO(pro, "liveness_levels", c.liveness_levels);
  SAVE_JSON_TO(j, "pro", pro);
}

Config Config::instance_;

Config::ptr Config::get_instance() { return Config::ptr(&instance_); }

void Config::load_defaults() {
  app = {
      .server_port = 8010,
      .server_host = "0.0.0.0",
      .image_store_path = "/user/quface-app/var/db/upload/",
      .person_service_base_url = "http://127.0.0.1",
  };

  user = {
      .blacklist_policy = "alarm",
      .detect_level = "medium",
      .extract_level = "medium",
      .liveness_level = "medium",
      .duplication_interval = 60,
  };

  quface = {
      .product_key = "",
      .device_name = "",
      .device_secret = "",
      .client_id = "face-service",
      .db_name = "quface",
      .model_file_path = "facemodel.bin",
      .license_filename = "license.json",
  };

  normal = {
      .index = 1,
      .rotate = 0,
      .flip = -2,
      .min_face_height = 100,
      .min_face_width = 100,
      .max_window_height = 800,
      .max_window_width = 600,
      .target_area_width_percent = 60,
      .target_area_height_percent = 60,
  };

  infrared = {
      .index = 1,
      .rotate = 0,
      .flip = -2,
      .min_face_height = 100,
      .min_face_width = 100,
      .max_window_height = 800,
      .max_window_width = 600,
      .target_area_width_percent = 60,
      .target_area_height_percent = 60,
  };

  default_detect_ = {
      .threshold = 0.4f,
      .min_face_size = 40,
      .max_yaw = 25,
      .min_yaw = -25,
      .max_pitch = 90,   // disable max pitch
      .min_pitch = -90,  // disable min pitch
  };

  default_extract_ = {
      .history_size = 15,
      .min_recognize_count = 10,
      .min_recognize_score = .75f,
      .min_accumulate_score = 7.0f,
      .max_lost_age = 20,
      .min_interval_between_same_records = 60,
      .show_black_list = 1,
  };

  default_liveness_ = {
      .enable = true,
      .history_size = 16,
      .min_alive_count = 7,
      .continuous_max_lost_count = 3,
  };

  detect_levels = {
    {"high", default_detect_},
    {"medium", default_detect_},
    {"low", default_detect_},
  };

  extract_levels = {
    {"high", default_extract_},
    {"medium", default_extract_},
    {"low", default_extract_},
  };

  liveness_levels = {
    {"high", default_liveness_},
    {"medium", default_liveness_},
    {"low", default_liveness_},
  };
}

SZ_RETCODE Config::load_from_file(const std::string &config_file,
                                  const std::string &config_override_file) {
  config_file_ = config_file;
  config_override_file_ = config_override_file;
  reload();
}

SZ_RETCODE Config::load_from_json(const json &j) { j.get_to(*this); }

SZ_RETCODE Config::reload() {
  try {
    std::ifstream i(config_file_);
    if (!i.is_open()) {
      SZ_LOG_WARN("{} not present, will using defaults", config_file_);
      return SZ_RETCODE_OK;
    }

    json config;
    i >> config;

    config.get_to(*this);

    std::ifstream override(config_override_file_);
    if (override.is_open()) {
      SZ_LOG_INFO("Override config from {}", config_override_file_);
      json override_config;
      i >> override_config;

      override_config.get_to(*this);
    }
  } catch (std::exception &exc) {
    SZ_LOG_ERROR("Load error, will using defaults: {}", exc.what());
  }

  return SZ_RETCODE_OK;
}

SZ_RETCODE Config::save() {
  json config = json(*this);

  std::ofstream o(config_override_file_);
  if (!o.is_open()) {
    SZ_LOG_WARN("Open {} failed, can't save", config_override_file_);
    return SZ_RETCODE_FAILED;
  }

  o << config.dump();

  return SZ_RETCODE_OK;
}

const DetectConfig &Config::get_detect() {
  auto &i = instance_;
  if (i.detect_levels.find(i.user.detect_level) != i.detect_levels.end()) {
    return i.detect_levels[i.user.detect_level];
  }
  return i.default_detect_;
}

const ExtractConfig &Config::get_extract() {
  auto &i = instance_;
  if (i.extract_levels.find(i.user.extract_level) != i.extract_levels.end()) {
    return i.extract_levels[i.user.extract_level];
  }
  return i.default_extract_;
}

const LivenessConfig &Config::get_liveness() {
  auto &i = instance_;
  if (i.liveness_levels.find(i.user.liveness_level) !=
      i.liveness_levels.end()) {
    return i.liveness_levels[i.user.liveness_level];
  }
  return i.default_liveness_;
}

bool Config::is_liveness_enable() { return Config::get_liveness().enable; }
