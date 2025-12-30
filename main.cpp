#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "converter.cpp"

using namespace std;

void writeJSON(vector<vector<double>>& vs,const string& path) {
  ofstream out(path, std::ios::trunc);

  out << "[\n";
  for(int i = 0; i < vs.size(); i++) {
    out << " [" << vs[i][0] << ", " << vs[i][1] << ", " << vs[i][2] << "]";
    if(i + 1 < vs.size()) out << ", ";
    out << "\n";
  }

  out << "]\n";
}

int main(void) {

  vector<vector<double>> poly;
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

    vector<int> input = {x, y, z};
    poly.emplace_back(c.convert(input));
  }

  writeJSON(poly, "points.json");
  system("python3 generator.py");
  return 0;
}
