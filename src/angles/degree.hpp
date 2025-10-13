#pragma once

class Radian;

class Degree {
private:
  float value;

public:
  Degree(float value);
  Degree(const Radian& value);

  float getDegree() const;
  void setDegree(float value);
  void addDegree(float delta);
};