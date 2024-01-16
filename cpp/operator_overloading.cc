
#include <iostream>
#include <string>

class Vector2 {
public:
  float x, y;

  Vector2(float x, float y) : x(x), y(y) {};

  Vector2 operator+(const Vector2& vec) const {
    return Vector2(x + vec.x, y + vec.y);
  }

  bool operator==(const Vector2& vec) const {
    return (x == vec.x && y == vec.y);
  }
};


std::ostream& operator<<(std::ostream& stream, const Vector2& vec){
  stream << "Result (x, y): (" << vec.x << ", " << vec.y << ")";
  return stream;
}


int main(){

  Vector2 position(4.0f, 4.0f);
  Vector2 speed(0.5f, 1.5f);

  Vector2 result = position + speed;
  std::cout << result << std::endl;

  std::cout << "Is position == speed: " << (position == speed) << std::endl;

}
