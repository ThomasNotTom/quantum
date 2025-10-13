#pragma once

class Degree;

class Radian {
private:
  float value;

public:
  Radian(float value);
  Radian(const Degree& degree);

  float getRadians() const;
  void setRadians(float value);
  void addRadians(float delta);
};