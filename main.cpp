#include <iostream>
#include <vector>
#include "converter.cpp"

using namespace std;

int main(void) {

  vector<vector<float>> poly;
  vector<int> input;
  int points {0};
  Convert c;

  cout << "============= HTML 3D RENDERING ==============" << endl;
  cout << "Enter the number of points of the polyhedron: ";
  cin >> points;
  cout << "Enter the points\n";

  for(int i{0}; i < points; ++i) {
    int x, y, z;

    cout << "Point #" << i+1 << ": ";
    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;
    cout << "Z: ";
    cin >> z;

    input.emplace_back(x);
    input.emplace_back(y);
    input.emplace_back(z);

    poly.emplace_back(c.convert(input));
  }

  return 0;
}
